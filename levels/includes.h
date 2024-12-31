#pragma once

#include <tonc.h>

// stereomadness
#define stereomadness_ID 0

#include "stereomadness/l1.h"
#include "stereomadness/l2.h"
#include "stereomadness/SP.h"
#include "stereomadness/properties.h"

// backontrack
#define backontrack_ID 1

#include "backontrack/l1.h"
#include "backontrack/l2.h"
#include "backontrack/SP.h"
#include "backontrack/properties.h"

// polargeist
#define polargeist_ID 2

#include "polargeist/l1.h"
#include "polargeist/l2.h"
#include "polargeist/SP.h"
#include "polargeist/properties.h"

// dryout
#define dryout_ID 3

#include "dryout/l1.h"
#include "dryout/l2.h"
#include "dryout/SP.h"
#include "dryout/properties.h"

// baseafterbase
#define baseafterbase_ID 4

#include "baseafterbase/l1.h"
#include "baseafterbase/l2.h"
#include "baseafterbase/SP.h"
#include "baseafterbase/properties.h"

// jumper
#define jumper_ID 5

#include "jumper/l1.h"
#include "jumper/l2.h"
#include "jumper/SP.h"
#include "jumper/properties.h"

// timemachine
#define timemachine_ID 6

#include "timemachine/l1.h"
#include "timemachine/l2.h"
#include "timemachine/SP.h"
#include "timemachine/properties.h"

// cycles
#define cycles_ID 7

#include "cycles/l1.h"
#include "cycles/l2.h"
#include "cycles/SP.h"
#include "cycles/properties.h"

// test
#define test_ID 8

#include "test/l1.h"
#include "test/l2.h"
#include "test/SP.h"
#include "test/properties.h"

#define LEVEL_COUNT 9
extern const u16 *level_defines[][4];
extern const u8 *level_names[];
