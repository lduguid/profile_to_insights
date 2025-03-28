#pragma once

#define PROFILEFILENAME "C:\\Users\\User\\Desktop\\work\\SST-2025-001\\profile.info.snapshot"

#define PROFILESEPARATOR    '|'

#define PROFILEFILTER       "[FILTER]"
#define PROFILEFKEY         "[FIELD]"
#define PROFILEFNAME        "NAME"
#define PROFILEFTYPE        "TYPE"
#define PROFILEINVALID      "INVALID"
#define PROFILEVALID        "VALID"
#define PROFILEALLZERO      "ALL_ZERO"
#define PROFILESTARTZERO    "START_ZERO"
#define PROFILEBLANKS       "BLANKS"
#define PROFILEMAX          "MAX"
#define PROFILEMIN          "MIN"
#define PROFILEAVERAGE      "AVER"
#define PROFILERANGE        "RANGE"
#define PROFILEPOS          "POSITIVE"
#define PROFILEPOSTOT       "POSITIVE_TOTAL"
#define PROFILENEG          "NEGATIVE"
#define PROFILENEGTOT       "NEGATIVE_TOTAL"
#define PROFILEZERO         "ZERO"
#define PROFILETOT          "TOTAL"
#define PROFILEVARIANCE     "VARIANCE"
#define PROFILESTDEV        "STDEV"
#define PROFILEKURT         "KURTOSIS" 
#define PROFILESKEW         "SKEWNESS" 
#define PROFILEWEEKENDS     "WEEKENDS"
#define PROFILEYEAR         "YEAR"
#define PROFILEMONTH        "MONTH"
#define PROFILEDOW          "DOW"
#define PROFILEDOM          "DOM"
#define PROFILEQUARTER      "QUARTER"
#define PROFILEDOY          "DOY"
#define PROFILEHOURS        "HOURS"
#define PROFILEMINUTES      "MINUTES"
#define PROFILEUNIQUE       "UNIQUE"
#define PROFILEUNIQUEONE    "UNIQUE_ONE"
#define PROFILEMEDIAN       "MEDIAN"
#define PROFILELEADINGBL    "LEADING_BLANK"
#define PROFILETRAILINGBL   "TRAILING_BLANK"
#define PROFILESORTA        "SORTA"
#define PROFILESORTD        "SORTD"
#define PROFILELOWEST       "LOWEST"
#define PROFILEHIGHEST      "HIGHEST"
#define PROFILEMOSTCOMMON   "MOST_COMMON"
#define PROFILELEASTCOMMON  "LEAST_COMMON"
#define PROFILELONGEST      "LONGEST"
#define PROFILESHORTEST     "SHORTEST"
#define PROFILEFRMUNIQUE    "FORMAT_UNIQUE"
#define PROFILEFRMUNIQUEONE "FORMAT_UNIQUE_ONE"
#define PROFILEFRMMOSTCMN   "FORMAT_MOST_COMMON"
#define PROFILEFRMLEASTCMN  "FORMAT_LEAST_COMMON"
#define PROFILELLN          "LLN"
#define PROFILELLR          "LLR"
#define PROFILELLD          "LLD"
#define PROFILEQ25          "Q25"
#define PROFILEQ75          "Q75"
#define PROFILESTA          "STRAT"
#define CATVERIFICATION     "CATVERIF"
#define CATSTATISTICS       "CATSTAT"
#define CATDISTRIBUTION     "CATDESTRIB"
#define CATDATETIME         "CATDT"
#define CATOUTLIERS         "CATOUTLRS"
#define CATFORMATS          "CATFMT"


typedef struct {
  const char* name;
  int type;
  int cat;
  int subcat;
  int subsubcat;
  int subsubsubcat;
  int subsubsubsubcat;
  int subsubsubsubsubcat;
} profile_info;

typedef struct {
	const char* name;
	const char* output_filename;
} profile_category;

profile_category profile_categories[] = {
	{CATVERIFICATION, "Verification.tsv" },
	{CATSTATISTICS, "Statistics.tsv"},
	{CATDISTRIBUTION, "Distribution.tsv"},
	{CATDATETIME, "DateTime.tsv"},
	{CATOUTLIERS, "Outliers.tsv"},
	{CATFORMATS, "Formats.tsv"}
};


profile_info profile_info_list[] =
{
	{CATVERIFICATION,		  1, 2, 3, 4, 5, 6, 7},
	{PROFILEINVALID,		  1, 2, 3, 4, 5, 6, 7},
	{PROFILEVALID,			  1, 2, 3, 4, 5, 6, 7},
	{PROFILEALLZERO,		  1, 2, 3, 4, 5, 6, 7},
	{PROFILESTARTZERO,	  1, 2, 3, 4, 5, 6, 7},
	{PROFILEBLANKS,			  1, 2, 3, 4, 5, 6, 7},
	{PROFILELEADINGBL,	  1, 2, 3, 4, 5, 6, 7},
	{PROFILETRAILINGBL,   1, 2, 3, 4, 5, 6, 7},
	{PROFILESORTA,			  1, 2, 3, 4, 5, 6, 7},
	{PROFILESORTD,			  1, 2, 3, 4, 5, 6, 7},
											  
	{CATSTATISTICS,			  1, 2, 3, 4, 5, 6, 7},
	{PROFILEMAX,				  1, 2, 3, 4, 5, 6, 7},
	{PROFILEMIN,				  1, 2, 3, 4, 5, 6, 7},
	{PROFILEAVERAGE,		  1, 2, 3, 4, 5, 6, 7},
	{PROFILERANGE,			  1, 2, 3, 4, 5, 6, 7},
	{PROFILEPOS,				  1, 2, 3, 4, 5, 6, 7},
	{PROFILEPOSTOT,			  1, 2, 3, 4, 5, 6, 7},
	{PROFILENEG,				  1, 2, 3, 4, 5, 6, 7},
	{PROFILENEGTOT,			  1, 2, 3, 4, 5, 6, 7},
	{PROFILEZERO,				  1, 2, 3, 4, 5, 6, 7},
	{PROFILETOT,				  1, 2, 3, 4, 5, 6, 7},
											  
	{CATDISTRIBUTION,		  1, 2, 3, 4, 5, 6, 7},
	{PROFILEQ25,				  1, 2, 3, 4, 5, 6, 7},
	{PROFILEMEDIAN,			  1, 2, 3, 4, 5, 6, 7},
	{PROFILEQ75,				  1, 2, 3, 4, 5, 6, 7},
	{PROFILEVARIANCE,		  1, 2, 3, 4, 5, 6, 7},
	{PROFILESTDEV,			  1, 2, 3, 4, 5, 6, 7},
	{PROFILEKURT,				  1, 2, 3, 4, 5, 6, 7},
	{PROFILESKEW,				  1, 2, 3, 4, 5, 6, 7},
											  
	{CATDATETIME,				  1, 2, 3, 4, 5, 6, 7},
	{PROFILEWEEKENDS,		  1, 2, 3, 4, 5, 6, 7},
	{PROFILEYEAR,				  1, 2, 3, 4, 5, 6, 7},
	{PROFILEMONTH,			  1, 2, 3, 4, 5, 6, 7},
	{PROFILEDOW,				  1, 2, 3, 4, 5, 6, 7},
	{PROFILEDOM,				  1, 2, 3, 4, 5, 6, 7},
	{PROFILEQUARTER,		  1, 2, 3, 4, 5, 6, 7},
	{PROFILEDOY,				  1, 2, 3, 4, 5, 6, 7},
	{PROFILEHOURS,			  1, 2, 3, 4, 5, 6, 7},
	{PROFILEMINUTES,		  1, 2, 3, 4, 5, 6, 7},
											  
	{CATOUTLIERS,				  1, 2, 3, 4, 5, 6, 7},
	{PROFILELONGEST,		  1, 2, 3, 4, 5, 6, 7},
	{PROFILESHORTEST,		  1, 2, 3, 4, 5, 6, 7},
	{PROFILELOWEST,			  1, 2, 3, 4, 5, 6, 7},
	{PROFILEHIGHEST,		  1, 2, 3, 4, 5, 6, 7},
	{PROFILEMOSTCOMMON,   1, 2, 3, 4, 5, 6, 7},
	{PROFILELEASTCOMMON,  1, 2, 3, 4, 5, 6, 7},
	{PROFILEUNIQUE,			  1, 2, 3, 4, 5, 6, 7},
	{PROFILEUNIQUEONE,	  1, 2, 3, 4, 5, 6, 7},
											  
	{CATFORMATS,				  1, 2, 3, 4, 5, 6, 7},
	{PROFILEFRMUNIQUE,	  1, 2, 3, 4, 5, 6, 7},
	{PROFILEFRMUNIQUEONE, 1, 2, 3, 4, 5, 6, 7},
	{PROFILEFRMMOSTCMN,   1, 2, 3, 4, 5, 6, 7},
	{PROFILEFRMLEASTCMN,  1, 2, 3, 4, 5, 6, 7},
	{PROFILELLN,				  1, 2, 3, 4, 5, 6, 7},
	{PROFILELLR,				  1, 2, 3, 4, 5, 6, 7},
	{PROFILELLD,				  1, 2, 3, 4, 5, 6, 7},
	{PROFILESTA,				  1, 2, 3, 4, 5, 6, 7}
};


