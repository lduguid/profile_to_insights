#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "defines.h"


static bool is_category_start(const char* start_category, const char* current)
{
  if (strncmp(current, start_category, strlen(start_category)) == 0) 
    return true;
  
  return false;
}


static bool is_category_end(const char* start_category, const char* current)
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
  char fputs_buffer[1024] = { 0 };
  bool found_category = false;
  int found_field_key = 0;
  int found_profile_info_name = 0;
  int row_count = 0;

  for (int ii = 0; ii < sizeof(profile_categories) / sizeof(profile_categories[0]); ii++)
  {
    // open current category tsv file

    FILE* categoryFile = fopen(profile_categories[ii].output_filename, "w");
    if (categoryFile == NULL)
    {
      printf("Error: Could not open file %s\n", profile_categories[ii].output_filename);
      return 1;
    }

    for (int i = 0; i < sizeof(profile_info_list) / sizeof(profile_info_list[0]); i++)
    {
      if (!found_category && is_category_start(profile_categories[ii].name, profile_info_list[ii].name))
      {
        found_category = true;
        continue;
      }

      if (found_category && !is_category_end(profile_categories[ii].name, profile_info_list[ii].name))
      {
        sprintf(fputs_buffer, "Category: %s\n", profile_categories[ii].name);
        fputs(fputs_buffer, categoryFile);

        while (fgets(buffer, 1024, profileFile) != NULL)
        {
          // NEED to find in each '[FIELD]' block or blank cell.

          if (strncmp(buffer, PROFILEFKEY, strlen(PROFILEFKEY)) == 0)
          {
            if (found_field_key != found_profile_info_name)
            {
              sprintf(fputs_buffer, "*blank*\n");
              fputs(fputs_buffer, categoryFile);
              found_profile_info_name = found_field_key;
            }

            found_field_key++;
          }
          else if (strncmp(buffer, profile_info_list[i].name, strlen(profile_info_list[i].name)) == 0)
          {
            sprintf(fputs_buffer, "%s", buffer);
            fputs(fputs_buffer, categoryFile);
            found_profile_info_name++;
          }
          else if ((strncmp(buffer, PROFILEFNAME, strlen(PROFILEFNAME)) == 0))
          {
            sprintf(fputs_buffer, "%s", buffer);
            fputs(fputs_buffer, categoryFile);
          }
          else if ((strncmp(buffer, PROFILEFTYPE, strlen(PROFILEFTYPE)) == 0))
          {
            sprintf(fputs_buffer, "%s", buffer);
            fputs(fputs_buffer, categoryFile);
          }

          row_count++;
        }

        // capture potential blank with last column field.

        if (found_field_key != found_profile_info_name)
        {
          sprintf(fputs_buffer, "*blank*\n");
          fputs(fputs_buffer, categoryFile);
          found_profile_info_name = found_field_key;
        }

        found_field_key = 0;
        found_profile_info_name = 0;

        sprintf(fputs_buffer, "\n");
        fputs(fputs_buffer, categoryFile);
        fseek(profileFile, 0, SEEK_SET);
      }
      else
      {
        found_category = false;
      }
    }

    fclose(categoryFile);
  }

  fclose(profileFile);
  return 0;
}
