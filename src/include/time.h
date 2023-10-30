/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef __TIME_H__
#define __TIME_H__	1

#ifdef __cplusplus
extern "C" {
#endif

#include <internal/io.h>
#include <internal/types.h>

struct timespec {
  int tv_sec;         /* seconds,  range 0 to 59          */
  int tv_min;         /* minutes, range 0 to 59           */
  int tv_hour;        /* hours, range 0 to 23             */
  int tv_mday;        /* day of the month, range 1 to 31  */
  int tv_mon;         /* month, range 0 to 11             */
  int tv_year;        /* The number of years since 1900   */
  int tv_wday;        /* day of the week, range 0 to 6    */
  int tv_yday;        /* day in the year, range 0 to 365  */
  int tv_isdst;       /* daylight saving time             */
};

int nanosleep(const struct timespec *req, struct timespec *rem);

#ifdef __cplusplus
}
#endif

#endif
