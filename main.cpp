#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "defines.h"


static void get_column_key(char* row_buffer, char *key)
{
  char* equal = strchr(row_buffer, '=');
  strncpy(key, row_buffer, equal - row_buffer);
}


static char* get_column_value(char* column_name, char echr)
{
  char* equal = strchr(column_name, '=');
  equal++;
  char* end = strchr(equal, echr);
  if (end) *end = '\0';
  return equal;
}


static void add_field_type_list(int index, data_field *cdf)
{
  
  // add a new node
  data_fields* head = &data_fields_types_list[index];
  data_fields *next = data_fields_types_list[index].dfs;
 
  if (next == nullptr && strlen(data_fields_types_list[index].df.name) == 0)
  {
    if (cdf) data_fields_types_list[index].df = *cdf;
  }
  else
  {
    data_fields* curr = head;
    data_fields* prev = curr;
    while (curr)
    {
      prev = curr;
      curr = curr->dfs;
    }

    if (prev)
    {
      prev->dfs = (data_fields*)malloc(sizeof(data_fields));
      if (cdf) prev->dfs->df = *cdf;
      prev->dfs->dfs = nullptr;
    }
  }
}


static void populate_value(char *buf, data_field *cdf)
{
  char key[128] = { 0 };
  get_column_key(buf, key);
  const char* value = get_column_value(buf, '\n');
  char* val = (char*)malloc(strlen(value) + 1);
  if (val) strcpy(val, value);

  if (cdf)
  {
    // VERIFICATION
    if      (strcmp(key, PROFILEINVALID) == 0) cdf->pdf->INVALID.value = val;
    else if (strcmp(key, PROFILEVALID) == 0) cdf->pdf->VALID.value = val;
    else if (strcmp(key, PROFILEALLZERO) == 0) cdf->pdf->ALL_ZERO.value = val;
    else if (strcmp(key, PROFILESTARTZERO) == 0) cdf->pdf->START_ZERO.value = val;
    else if (strcmp(key, PROFILEBLANKS) == 0) cdf->pdf->BLANKS.value = val;
    else if (strcmp(key, PROFILELEADINGBL) == 0) cdf->pdf->LEADING_BLANK.value = val;
    else if (strcmp(key, PROFILETRAILINGBL) == 0) cdf->pdf->TRAILING_BLANK.value = val;
    else if (strcmp(key, PROFILESORTA) == 0) cdf->pdf->SORTA.value = val;
    else if (strcmp(key, PROFILESORTD) == 0) cdf->pdf->SORTB.value = val;
    // STATISTICS
    else if (strcmp(key, PROFILEMAX) == 0) cdf->pdf->MAX.value = val;
    else if (strcmp(key, PROFILEMIN) == 0) cdf->pdf->MIN.value = val;
    else if (strcmp(key, PROFILEAVERAGE) == 0) cdf->pdf->AVER.value = val;
    else if (strcmp(key, PROFILERANGE) == 0) cdf->pdf->RANGE.value = val;
    else if (strcmp(key, PROFILEPOS) == 0) cdf->pdf->POSITIVE.value = val;
    else if (strcmp(key, PROFILEPOSTOT) == 0) cdf->pdf->POSITIVE_TOTAL.value = val;
    else if (strcmp(key, PROFILENEG) == 0) cdf->pdf->NEGATIVE.value = val;
    else if (strcmp(key, PROFILENEGTOT) == 0) cdf->pdf->NEGATIVE_TOTAL.value = val;
    else if (strcmp(key, PROFILEZERO) == 0) cdf->pdf->ZERO.value = val;
    else if (strcmp(key, PROFILETOT) == 0) cdf->pdf->TOTAL.value = val;
    // DISTRIBUTION
    else if (strcmp(key, PROFILEQ25) == 0) cdf->pdf->Q25.value = val;
    else if (strcmp(key, PROFILEMEDIAN) == 0) cdf->pdf->MEDIAN.value = val;
    else if (strcmp(key, PROFILEQ75) == 0) cdf->pdf->Q75.value = val;
    else if (strcmp(key, PROFILEVARIANCE) == 0) cdf->pdf->VARIANCE.value = val;
    else if (strcmp(key, PROFILESTDEV) == 0) cdf->pdf->STDEV.value = val;
    else if (strcmp(key, PROFILEKURT) == 0) cdf->pdf->KURTOSIS.value = val;
    else if (strcmp(key, PROFILESKEW) == 0) cdf->pdf->SKEWNESS.value = val;
    // DATETIME
    else if (strcmp(key, PROFILEWEEKENDS) == 0) cdf->pdf->WEEKENDS.value = val;
    else if (strcmp(key, PROFILEYEAR) == 0) cdf->pdf->YEAR.value = val;
    else if (strcmp(key, PROFILEMONTH) == 0) cdf->pdf->MONTH.value = val;
    else if (strcmp(key, PROFILEDOW) == 0) cdf->pdf->DOW.value = val;
    else if (strcmp(key, PROFILEDOM) == 0) cdf->pdf->DOM.value = val;
    else if (strcmp(key, PROFILEQUARTER) == 0) cdf->pdf->QUARTER.value = val;
    else if (strcmp(key, PROFILEDOY) == 0) cdf->pdf->DOY.value = val;
    else if (strcmp(key, PROFILEHOURS) == 0) cdf->pdf->HOURS.value = val;
    else if (strcmp(key, PROFILEMINUTES) == 0) cdf->pdf->MINUTES.value = val;
    // OUTLIERS
    else if (strcmp(key, PROFILELONGEST) == 0) cdf->pdf->LONGEST.value = val;
    else if (strcmp(key, PROFILESHORTEST) == 0) cdf->pdf->SHORTEST.value = val;
    else if (strcmp(key, PROFILELOWEST) == 0) cdf->pdf->LOWEST.value = val;
    else if (strcmp(key, PROFILEHIGHEST) == 0) cdf->pdf->HIGHEST.value = val;
    else if (strcmp(key, PROFILEMOSTCOMMON) == 0) cdf->pdf->FORMAT_MOST_COMMON.value = val;
    else if (strcmp(key, PROFILELEASTCOMMON) == 0) cdf->pdf->LEAST_COMMON.value = val;
    else if (strcmp(key, PROFILEUNIQUE) == 0) cdf->pdf->UNIQUE.value = val;
    else if (strcmp(key, PROFILEUNIQUEONE) == 0) cdf->pdf->UNIQUE_ONE.value = val;
    // FORMAT
    else if (strcmp(key, PROFILEFRMUNIQUE) == 0) cdf->pdf->FORMAT_UNIQUE.value = val;
    else if (strcmp(key, PROFILEFRMUNIQUEONE) == 0) cdf->pdf->FORMAT_UNIQUE_ONE.value = val;
    else if (strcmp(key, PROFILEFRMMOSTCMN) == 0) cdf->pdf->FORMAT_MOST_COMMON.value = val;
    else if (strcmp(key, PROFILEFRMLEASTCMN) == 0) cdf->pdf->FORMAT_LEAST_COMMON.value = val;
    else if (strcmp(key, PROFILELLN) == 0) cdf->pdf->LLN.value = val;
    else if (strcmp(key, PROFILELLR) == 0) cdf->pdf->LLR.value = val;
    else if (strcmp(key, PROFILELLD) == 0) cdf->pdf->LLD.value = val;
    else if (strcmp(key, PROFILESTA) == 0) cdf->pdf->STRAT.value = val;
    else printf("key: %s, not found!", key);
  }
}


static void output_verification(int i, int fpfi, data_fields* curr, profile_data_fields* pdf, FILE *categoryFile)
{
  if (i == 0)   // first field node.
  {
    if (fpfi == 1) fputs(pdf->INVALID.profile_name, categoryFile);
    else if (fpfi == 2) fputs(pdf->VALID.profile_name, categoryFile);
    else if (fpfi == 3) fputs(pdf->ALL_ZERO.profile_name, categoryFile);
    else if (fpfi == 4) fputs(pdf->START_ZERO.profile_name, categoryFile);
    else if (fpfi == 5) fputs(pdf->BLANKS.profile_name, categoryFile);
    else if (fpfi == 6) fputs(pdf->LEADING_BLANK.profile_name, categoryFile);
    else if (fpfi == 7) fputs(pdf->TRAILING_BLANK.profile_name, categoryFile);
    else if (fpfi == 8) fputs(pdf->SORTA.profile_name, categoryFile);
    else if (fpfi == 9) fputs(pdf->SORTB.profile_name, categoryFile);
  }

  while (curr)
  {
    pdf = curr->df.pdf;
    fputs("\t", categoryFile);
    if (fpfi == 1) fputs(pdf->INVALID.value ? pdf->INVALID.value : "", categoryFile);
    else if (fpfi == 2) fputs(pdf->VALID.value ? pdf->VALID.value : "", categoryFile);
    else if (fpfi == 3) fputs(pdf->ALL_ZERO.value ? pdf->ALL_ZERO.value : "", categoryFile);
    else if (fpfi == 4) fputs(pdf->START_ZERO.value ? pdf->START_ZERO.value : "", categoryFile);
    else if (fpfi == 5) fputs(pdf->BLANKS.value ? pdf->BLANKS.value : "", categoryFile);
    else if (fpfi == 6) fputs(pdf->LEADING_BLANK.value ? pdf->LEADING_BLANK.value : "", categoryFile);
    else if (fpfi == 7) fputs(pdf->TRAILING_BLANK.value ? pdf->TRAILING_BLANK.value : "", categoryFile);
    else if (fpfi == 8) fputs(pdf->SORTA.value ? pdf->SORTA.value : "", categoryFile);
    else if (fpfi == 9) fputs(pdf->SORTB.value ? pdf->SORTB.value : "", categoryFile);

    curr = curr->dfs;
  }
}

// requires an profile.info file in the CWD.  If RUN from analyzer, ensure profile tab open (profile.info deleted on tab close)
// heap memory is not expliclty freed!  As the lifetime of this memory is the the duration fo the executable, OS cleans it all up on exit.
// if this code is to be re-purposed in an larger application, free'ing will be required.

int main(char argc, char* argv[])
{
  // INPUT - read input file PROFILEFILENAME and populate internal ADT to represent its contents

  FILE *profileFile = fopen(PROFILEFILENAME, "r");
  if (profileFile == NULL)
  {
    printf("Error: Could not open file %s\n", PROFILEFILENAME);
    return 1;
  }

  char raw_buffer[8196] = { 0 };

  while (fgets(raw_buffer, 8196, profileFile) != NULL)
  {
    data_field* cdf = nullptr;

    if (strncmp(raw_buffer, PROFILEFKEY, strlen(PROFILEFKEY)) == 0)
    {
      fgets(raw_buffer, 8196, profileFile);       // slurp up PROFILEFKEY
    }
    
    if (strncmp(raw_buffer, PROFILEFNAME, strlen(PROFILEFNAME)) == 0)
    {
      const char* column_name = get_column_value(raw_buffer, ' ');
      cdf = (data_field*) malloc(sizeof(data_field));
      strcpy(cdf->name, column_name);

      cdf->pdf = (profile_data_fields*)malloc(sizeof(profile_data_fields));
      memcpy(cdf->pdf, (profile_data_fields*)&profile_data, sizeof(profile_data));

      fgets(raw_buffer, 8196, profileFile);       // slurp up PROFILEFNAME
    }
    
    if ((strncmp(raw_buffer, PROFILEFTYPE, strlen(PROFILEFTYPE)) == 0))
    {
      int index = 0;
      const char* column_type = get_column_value(raw_buffer, '\n');
      if      (column_type[0] == 'C') index = 0;
      else if (column_type[0] == 'N') index = 1;
      else if (column_type[0] == 'D') index = 2;
      else if (column_type[0] == 'L') index = 3;
      else printf("Column Type: %c, is not a valid index.", column_type[0]);
      
      add_field_type_list(index, cdf);
    }

    while (fgets(raw_buffer, 8196, profileFile) != NULL)
    {
      if (strncmp(raw_buffer, PROFILEFKEY, strlen(PROFILEFKEY)) == 0)
        break;

      populate_value(raw_buffer, cdf);
    }
  }

  if (profileFile) fclose(profileFile);


  // OUTPUT - traverse and write out internal ADT of profile data on each column to the requested tab-seperated output files.

 
  // iterate over each profile data out file

  for (int ii = 0; ii < sizeof(profile_category_files) / sizeof(profile_category_files[0]); ii++)
  {
    // open current category tsv file

    FILE *categoryFile = fopen(profile_category_files[ii].output_filename, "w");
    if (categoryFile == NULL)
    {
      printf("Error: Could not open file %s\n", profile_category_files[ii].output_filename);
      return 1;
    }

    // do for column headers, then profile data
    
    int row_count = 0;

    for (int fpfi = 0; fpfi  < (profile_category_files[ii].field_count + 1); fpfi++)
    {
      // iterate over data field columns in same order used in profile tab.

      for (int i = 0; i < 4; i++)
      {
        data_fields* head = &data_fields_types_list[i];
        data_fields* curr = head;

        // header columns

        if (strlen(curr->df.name) > 0)
        {
          if (row_count == 0)
          {
            while (curr)
            {
              fputs("\t", categoryFile);
              fputs(curr->df.name, categoryFile);

              curr = curr->dfs;
            }
          }
          else
          {
            // profile data

            curr = head;
            
            profile_data_fields* pdf = curr->df.pdf;

            if (strcmp(profile_category_files[ii].catname, CATVERIFICATION) == 0)
            {
              output_verification(i, fpfi, curr, pdf, categoryFile);
            }
            // TODO other categories
           
          }
        }
      }

      row_count++;
      
      // append newline to row.
      
      fputs("\n", categoryFile);
    }

    // close file

    if (categoryFile) fclose(categoryFile);
  }

  return 0;
}
