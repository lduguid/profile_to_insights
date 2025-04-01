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
	const char* catname;
	int field_count;
	const char* output_filename;
} profile_category;


profile_category profile_category_files[] = {
	{CATVERIFICATION,  9, "Verification.tsv" },
	{CATSTATISTICS,		10, "Statistics.tsv"	 },
	{CATDISTRIBUTION,  7, "Distribution.tsv" },
	{CATDATETIME,			 9, "DateTime.tsv"     },
	{CATOUTLIERS,			 8, "Outliers.tsv"     },
	{CATFORMATS,			 8, "Formats.tsv"      }
};


typedef struct {
	const char* profile_name;
	const char* category_name;
	char* value;
} profile_datum;


typedef struct {
	profile_datum INVALID;
	profile_datum VALID;
	profile_datum ALL_ZERO;
	profile_datum START_ZERO;
	profile_datum BLANKS;
	profile_datum LEADING_BLANK;
	profile_datum TRAILING_BLANK;
	profile_datum SORTA;
	profile_datum SORTB;
	profile_datum MAX;
	profile_datum MIN;
	profile_datum AVER;
	profile_datum RANGE;
	profile_datum POSITIVE;
	profile_datum POSITIVE_TOTAL;
	profile_datum NEGATIVE;
	profile_datum NEGATIVE_TOTAL;
	profile_datum ZERO;
	profile_datum TOTAL;
	profile_datum Q25;
	profile_datum MEDIAN;
	profile_datum Q75;
	profile_datum VARIANCE;
	profile_datum STDEV;
	profile_datum KURTOSIS;
	profile_datum SKEWNESS;
	profile_datum WEEKENDS;
	profile_datum YEAR;
	profile_datum MONTH;
	profile_datum DOW;
	profile_datum DOM;
	profile_datum QUARTER;
	profile_datum DOY;
	profile_datum HOURS;
	profile_datum MINUTES;
	profile_datum LONGEST;
	profile_datum SHORTEST;
	profile_datum LOWEST;
	profile_datum HIGHEST;
	profile_datum MOST_COMMON;
	profile_datum LEAST_COMMON;
	profile_datum UNIQUE;
	profile_datum UNIQUE_ONE;
	profile_datum FORMAT_UNIQUE;
	profile_datum FORMAT_UNIQUE_ONE;
	profile_datum FORMAT_MOST_COMMON;
	profile_datum FORMAT_LEAST_COMMON;
	profile_datum LLN;
	profile_datum LLR;
	profile_datum LLD;
	profile_datum STRAT;

} profile_data_fields;


profile_data_fields profile_data = {
	.INVALID							= {.profile_name = {PROFILEINVALID			}, .category_name = {CATVERIFICATION	}, .value = nullptr },
	.VALID								= {.profile_name = {PROFILEVALID				}, .category_name = {CATVERIFICATION	}, .value = nullptr },
	.ALL_ZERO							= {.profile_name = {PROFILEALLZERO			}, .category_name = {CATVERIFICATION	}, .value = nullptr },
	.START_ZERO						= {.profile_name = {PROFILESTARTZERO		}, .category_name = {CATVERIFICATION	}, .value = nullptr },
	.BLANKS								= {.profile_name = {PROFILEBLANKS				}, .category_name = {CATVERIFICATION	}, .value = nullptr },
	.LEADING_BLANK				= {.profile_name = {PROFILELEADINGBL		}, .category_name = {CATVERIFICATION	}, .value = nullptr },
	.TRAILING_BLANK				= {.profile_name = {PROFILETRAILINGBL		}, .category_name = {CATVERIFICATION	}, .value = nullptr },
	.SORTA								=	{.profile_name = {PROFILESORTA				}, .category_name = {CATVERIFICATION	}, .value = nullptr },
	.SORTB								= {.profile_name = {PROFILESORTD				}, .category_name = {CATVERIFICATION	}, .value = nullptr },
	.MAX									= {.profile_name = {PROFILEMAX					}, .category_name = {CATSTATISTICS		}, .value = nullptr },
	.MIN									= {.profile_name = {PROFILEMIN					}, .category_name = {CATSTATISTICS		}, .value = nullptr },
	.AVER									= {.profile_name = {PROFILEAVERAGE			}, .category_name = {CATSTATISTICS		}, .value = nullptr },
	.RANGE								= {.profile_name = {PROFILERANGE				}, .category_name = {CATSTATISTICS		}, .value = nullptr },
	.POSITIVE							= {.profile_name = {PROFILEPOS					}, .category_name = {CATSTATISTICS		}, .value = nullptr },
	.POSITIVE_TOTAL				= {.profile_name = {PROFILEPOSTOT				}, .category_name = {CATSTATISTICS		}, .value = nullptr },
	.NEGATIVE							= {.profile_name = {PROFILENEG					}, .category_name = {CATSTATISTICS		}, .value = nullptr },
	.NEGATIVE_TOTAL				= {.profile_name = {PROFILENEGTOT				}, .category_name = {CATSTATISTICS		}, .value = nullptr },
	.ZERO									= {.profile_name = {PROFILEZERO					}, .category_name = {CATSTATISTICS		}, .value = nullptr },
	.TOTAL								= {.profile_name = {PROFILETOT					}, .category_name = {CATSTATISTICS		}, .value = nullptr },
	.Q25									= {.profile_name = {PROFILEQ25					}, .category_name = {CATDISTRIBUTION	}, .value = nullptr },
	.MEDIAN								= {.profile_name = {PROFILEMEDIAN				}, .category_name = {CATDISTRIBUTION	}, .value = nullptr },
	.Q75									= {.profile_name = {PROFILEQ75					}, .category_name = {CATDISTRIBUTION	}, .value = nullptr },
	.VARIANCE							= {.profile_name = {PROFILEVARIANCE			}, .category_name = {CATDISTRIBUTION	}, .value = nullptr },
	.STDEV								= {.profile_name = {PROFILESTDEV				}, .category_name = {CATDISTRIBUTION	}, .value = nullptr },
	.KURTOSIS							= {.profile_name = {PROFILEKURT					}, .category_name = {CATDISTRIBUTION	}, .value = nullptr },
	.SKEWNESS							= {.profile_name = {PROFILESKEW					}, .category_name = {CATDISTRIBUTION	}, .value = nullptr },
	.WEEKENDS							= {.profile_name = {PROFILEWEEKENDS			}, .category_name = {CATDATETIME			}, .value = nullptr },
	.YEAR									= {.profile_name = {PROFILEYEAR					}, .category_name = {CATDATETIME			}, .value = nullptr },
	.MONTH								= {.profile_name = {PROFILEMONTH				}, .category_name = {CATDATETIME			}, .value = nullptr },
	.DOW									= {.profile_name = {PROFILEDOW					}, .category_name = {CATDATETIME			}, .value = nullptr },
	.DOM									= {.profile_name = {PROFILEDOM					}, .category_name = {CATDATETIME			}, .value = nullptr },
	.QUARTER							= {.profile_name = {PROFILEQUARTER			}, .category_name = {CATDATETIME			}, .value = nullptr },
	.DOY									= {.profile_name = {PROFILEDOY					}, .category_name = {CATDATETIME			}, .value = nullptr },
	.HOURS								= {.profile_name = {PROFILEHOURS				}, .category_name = {CATDATETIME			}, .value = nullptr },
	.MINUTES							= {.profile_name = {PROFILEMINUTES			}, .category_name = {CATDATETIME			}, .value = nullptr },
	.LONGEST							= {.profile_name = {PROFILELONGEST			}, .category_name = {CATOUTLIERS			}, .value = nullptr },
	.SHORTEST							= {.profile_name = {PROFILESHORTEST			}, .category_name = {CATOUTLIERS			}, .value = nullptr },
	.LOWEST								=	{.profile_name = {PROFILELOWEST				}, .category_name = {CATOUTLIERS			}, .value = nullptr },
	.HIGHEST							= {.profile_name = {PROFILEHIGHEST			}, .category_name = {CATOUTLIERS			}, .value = nullptr },
	.MOST_COMMON					= {.profile_name = {PROFILEMOSTCOMMON		}, .category_name = {CATOUTLIERS			}, .value = nullptr },
	.LEAST_COMMON					= {.profile_name = {PROFILELEASTCOMMON	}, .category_name = {CATOUTLIERS			}, .value = nullptr },
	.UNIQUE								= {.profile_name = {PROFILEUNIQUE				}, .category_name = {CATOUTLIERS			}, .value = nullptr },
	.UNIQUE_ONE						= {.profile_name = {PROFILEUNIQUEONE		}, .category_name = {CATOUTLIERS			}, .value = nullptr },
	.FORMAT_UNIQUE				= {.profile_name = {PROFILEFRMUNIQUE		}, .category_name = {CATFORMATS				}, .value = nullptr },
	.FORMAT_UNIQUE_ONE		= {.profile_name = {PROFILEFRMUNIQUEONE	}, .category_name = {CATFORMATS				}, .value = nullptr },
	.FORMAT_MOST_COMMON		= {.profile_name = {PROFILEFRMMOSTCMN		}, .category_name = {CATFORMATS				}, .value = nullptr },
	.FORMAT_LEAST_COMMON	= {.profile_name = {PROFILEFRMLEASTCMN	}, .category_name = {CATFORMATS				}, .value = nullptr },
	.LLN									= {.profile_name = {PROFILELLN					}, .category_name = {CATFORMATS				}, .value = nullptr },
	.LLR									= {.profile_name = {PROFILELLR					}, .category_name = {CATFORMATS				}, .value = nullptr },
	.LLD									= {.profile_name = {PROFILELLD					}, .category_name = {CATFORMATS				}, .value = nullptr },
	.STRAT								= {.profile_name = {PROFILESTA					}, .category_name = {CATFORMATS				}, .value = nullptr }
};


typedef struct
{
	char name[128];
	profile_data_fields *pdf;
} data_field;


typedef struct data_fields_tag
{
	data_field df;
	data_fields_tag* dfs;
} data_fields;


// index to type is 0 - 'C', 1 - 'N', 2 - 'D', 3 - 'L'

data_fields data_fields_types_list[4] = {
	{ .df = { .name = { 0 }, .pdf = { nullptr } }, .dfs = nullptr },
	{ .df = { .name = { 0 }, .pdf = { nullptr } }, .dfs = nullptr },
	{ .df = { .name = { 0 }, .pdf = { nullptr } }, .dfs = nullptr },
	{ .df = { .name = { 0 }, .pdf = { nullptr } }, .dfs = nullptr }
};
