#ifndef _CALENDAR_DISPLAY_UTILS_H_
#define _CALENDAR_DISPLAY_UTILS_H_

int draw_calendar(int day, int month, int year);
void clear_calendar(int nb_line);

void enableRawMode(struct termios *original);
void disableRawMode(struct termios *original);
void keyboardManager(int *quit, int *day, int *month, int *year);

#endif // _CALENDAR_DISPLAY_UTILS_H_