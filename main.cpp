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


static char* get_column_value(char* column_name, char echr)
{
  char* equal = strchr(column_name, '=');
  equal++;
  char* end = strchr(equal, echr);
  if (end) *end = '\0';
  return equal;
}


int main(char argc, char* argv[])
{

  FILE* profileFile = fopen(PROFILEFILENAME, "r");
  if (profileFile == NULL)
  {
    printf("Error: Could not open file %s\n", PROFILEFILENAME);
    return 1;
  }

  char raw_buffer[8196] = { 0 };

  char row_buffer[8196] = { 0 };
  char* cur_row_pos = row_buffer;
  
  char header_buffer[1024] = { 0 };
  char* cur_header_pos = header_buffer;

  bool found_category = false;
  int found_field_key = 0;
  int found_profile_info_name = 0;

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
      if (!found_category && is_category_start(profile_categories[ii].name, profile_info_list[i].name))
      {
        found_category = true;
        continue;
      }

      if (found_category && !is_category_end(profile_categories[ii].name, profile_info_list[i].name))
      {
        if (i == 1) 
          cur_header_pos += sprintf(cur_header_pos, "%s\t", profile_categories[ii].name);
          
        while (fgets(raw_buffer, 1024, profileFile) != NULL)
        {
          // NEED to find in each '[FIELD]' block or blank cell.

          if (strncmp(raw_buffer, PROFILEFKEY, strlen(PROFILEFKEY)) == 0)
          {
            if (found_field_key != found_profile_info_name)
            {
              cur_row_pos += sprintf(cur_row_pos, "\t");
              found_profile_info_name = found_field_key;
            }

            found_field_key++;
          }
          else if (strncmp(raw_buffer, profile_info_list[i].name, strlen(profile_info_list[i].name)) == 0)
          {
            if (row_buffer[0] == '\0')
              cur_row_pos += sprintf(cur_row_pos, "%s\t", profile_info_list[i].name);

            char* column_value = get_column_value(raw_buffer, '\n');
            cur_row_pos += sprintf(cur_row_pos, "%s\t", column_value);
            found_profile_info_name++;
          }
          else if ((strncmp(raw_buffer, PROFILEFNAME, strlen(PROFILEFNAME)) == 0))
          {
            if (i==1) 
              cur_header_pos += sprintf(cur_header_pos, "%s\t", get_column_value(raw_buffer, ' '));
          }
          else if ((strncmp(raw_buffer, PROFILEFTYPE, strlen(PROFILEFTYPE)) == 0))
          {
            // should only need type if we want to have the same field column order 
            // used on extended profile tab (C,D,N,L)
            ;
          }
        }

        // capture potential blank with last profile field block in profile.info.

        if (found_field_key != found_profile_info_name)
        {
          cur_row_pos += sprintf(cur_row_pos, "\t");
          found_profile_info_name = found_field_key;
        }

        found_field_key = 0;
        found_profile_info_name = 0;
        fseek(profileFile, 0, SEEK_SET);
      }
      else
      {
        found_category = false;
      }
      
      if (i == 1)
      {
        // replace last '\t' with '\n'
        char* end = strrchr(header_buffer, '\t');
        if (end) *end = '\n';
        fputs(header_buffer, categoryFile);
        cur_header_pos = header_buffer;
      }

      // replace last '\t' with '\n'
      char* end = strrchr(row_buffer, '\t');
      if (end) *end = '\n';
      fputs(row_buffer, categoryFile);
      row_buffer[0] = '\0';
      cur_row_pos = row_buffer;
    }

    fclose(categoryFile);
  }

  fclose(profileFile);
  return 0;
}
