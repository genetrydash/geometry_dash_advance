#include "includes.h"
const u16 *level_defines[][4] = {
   { stereomadness_l1_level_data, stereomadness_l2_level_data, stereomadness_spr_data, stereomadness_properties },
   { backontrack_l1_level_data, backontrack_l2_level_data, backontrack_spr_data, backontrack_properties },
   { polargeist_l1_level_data, polargeist_l2_level_data, polargeist_spr_data, polargeist_properties },
   { dryout_l1_level_data, dryout_l2_level_data, dryout_spr_data, dryout_properties },
   { baseafterbase_l1_level_data, baseafterbase_l2_level_data, baseafterbase_spr_data, baseafterbase_properties },
};
const u8 *level_names[] = {
   stereomadness_name,
   backontrack_name,
   polargeist_name,
   dryout_name,
   baseafterbase_name,
};
