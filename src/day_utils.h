#ifndef _CALENDAR_DAY_UTILS_H_
#define _CALENDAR_DAY_UTILS_H_

/**
 * Find the day of the week for the given date.
 * @param day the day
 * @param month the month
 * @param year the year
 * @return An int beetwen 0 and 6; 0 for monday, 6 for sunday.
 */
int weekday(int day, int month, int year);

/**
 * Check if a year is a leap year
 * @param year the year
 * @return 1 is leap year, 0 if not
 */
int is_bissextile(int year);

#endif // _CALENDAR_DAY_UTILS_H_