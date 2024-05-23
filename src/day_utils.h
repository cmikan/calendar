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
 * Check if a year is a leap year.
 * @param year the year
 * @return 1 is leap year, 0 otherwise.
 */
int is_bissextile(int year);

/**
 * Check if a date is valid.
 * @param day the day
 * @param month the month
 * @param year the year
 * @return 1 if the date is valid, 0 otherwise.
 */
int check_date(int day, int month, int year);

int day_in_month(int month, int year);
void month_name(int month, char **name);

#endif // _CALENDAR_DAY_UTILS_H_