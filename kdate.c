#include "types.h"
#include "date.h"

uint days[2][12] = {
  { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
  { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

uint date2time(struct rtcdate *dp) {
  int leap = (dp->year % 4 == 0 && dp->year % 100 != 0) || dp->year % 400 == 0;
  uint sumdays = dp->day;
  for (int i = 0; i < dp->month - 1; i++) sumdays += days[leap][i];
  return
      dp->second
    + dp->minute * 60
    + dp->hour * 3600
    + (   sumdays
        + dp->year*365
        + dp->year/4
        - dp->year/100
        + dp->year/400
        - 719163) * 86400;
}
