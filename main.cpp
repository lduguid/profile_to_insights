#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "defines.h"


bool is_category_start(const char* start_category, const char* current)
{
  if (strncmp(current, start_category, strlen(start_category)) == 0) return true;
  return false;
}


bool is_category_end(const char* start_category, const char* current)
{
  for (int i = 0; i < sizeof(profile_categories) / sizeof(profile_categories[0]); i++)
  {
    if ((strncmp(current, profile_categories[i].name, strlen(profile_categories[i].name)) == 0) &&
      (strncmp(current, start_category, strlen(start_category)) != 0))
      return true;
  }

  return false;
}


int main(char argc, char* argv[])
{

  FILE* profileFile = fopen(PROFILEFILENAME, "r");
  if (profileFile == NULL)
  {
    printf("Error: Could not open file %s\n", PROFILEFILENAME);
    return 1;
  }

  char buffer[1024] = { 0 };
  bool found_category = false;
  int found_field_key = 0;
  int found_profile_info_name = 0;
  int row_count = 0;

  for (int ii = 0; ii < sizeof(profile_categories) / sizeof(profile_categories[0]); ii++)
  {
    for (int i = 0; i < sizeof(profile_info_list) / sizeof(profile_info_list[0]); i++)
    {
      if (!found_category && is_category_start(profile_categories[ii].name, profile_info_list[ii].name))
      {
        found_category = true;
        continue;
      }

      if (found_category && !is_category_end(profile_categories[ii].name, profile_info_list[ii].name))
      {
        printf("Category: %s\n", profile_categories[ii].name);

        // NEED to find in each '[FIELD]' block or blank cell.
        while (fgets(buffer, 1024, profileFile) != NULL)
        {
          if (strncmp(buffer, PROFILEFKEY, strlen(PROFILEFKEY)) == 0)
          {
            if (found_field_key != found_profile_info_name)
            {
              printf("*blank*\n");
              found_profile_info_name = found_field_key;
            }

            found_field_key++;
          }
          else if (strncmp(buffer, profile_info_list[i].name, strlen(profile_info_list[i].name)) == 0)
          {
            printf("%s", buffer);
            found_profile_info_name++;
          }
          else if ((strncmp(buffer, PROFILEFNAME, strlen(PROFILEFNAME)) == 0))
          {
            printf("%s", buffer);
          }
          else if ((strncmp(buffer, PROFILEFTYPE, strlen(PROFILEFTYPE)) == 0))
          {
            printf("%s", buffer);
          }

          row_count++;
        }

        if (found_field_key != found_profile_info_name)
        {
          printf("*blank*\n");
          found_profile_info_name = found_field_key;
        }

        found_field_key = 0;
        found_profile_info_name = 0;

        printf("\n");
        fseek(profileFile, 0, SEEK_SET);
      }
      else
      {
        found_category = false;
      }
    }
  }

  fclose(profileFile);
  return 0;
}
