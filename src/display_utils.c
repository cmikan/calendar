#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

#include "day_utils.h"

int draw_calendar(int month, int year)
{
    int line_nb = 0;
    int nb_days = 0;
    char *mont_name;
    switch (month)
    {
        case 1:
            mont_name = "January";
            nb_days = 31;
            break;
        case 2:
            mont_name = "February";
            if (is_bissextile(year))
            {
                nb_days = 29;
            }
            else
            {
                nb_days = 28;
            }
            break;
        case 3:
            mont_name = "March";
            nb_days = 31;
            break;
        case 4:
            mont_name = "April";
            nb_days = 30;
            break;
        case 5:
            mont_name = "May";
            nb_days = 31;
            break;
        case 6:
            mont_name = "June";
            nb_days = 30;
            break;
        case 7:
            mont_name = "July";
            nb_days = 31;
            break;
        case 8:
            mont_name = "August";
            nb_days = 31;
            break;
        case 9:
            mont_name = "September";
            nb_days = 30;
            break;
        case 10:
            mont_name = "October";
            nb_days = 31;
            break;
        case 11:
            mont_name = "November";
            nb_days = 30;
            break;
        case 12:
            mont_name = "December";
            nb_days = 31;
            break;
    }

    printf("   \033[31m%s %d\033[0m\n", mont_name, year);

    printf("\033[93m mo tu we th fr sa su\033[0m\n");
    line_nb += 2;
    int empty_days = weekday(1, month, year);
    for (int i = 0; i < empty_days; i++)
    {
        printf("   ");
    }

    for (int i = 0; i < nb_days; i++)
    {
        if ((i + empty_days) % 7 == 0 && (i + empty_days) != 0)
        {
            printf("\n");
            line_nb += 1;
        }
        char *before;
        char *after;
        if ((i + empty_days) % 7 == 6) // Sunday
        {
            before = "\033[31m";
            after = "\033[0m";
        }
        else
        {
            before = "";
            after = "";
        }
        printf("%s%*d%s", before, 3, i + 1, after);
    }
    printf("\n");
    line_nb += 1;

    return line_nb;
}

void clear_calendar(int nb_line)
{
    for (int i = 0; i < nb_line; i++)
    {
        printf("\033[1A\033[M");
    }
}

void enableRawMode(struct termios *original)
{
    struct termios raw;

    tcgetattr(STDIN_FILENO, original);

    raw = *original;

    raw.c_lflag &= ~(ICANON | ECHO);
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 1;

    tcsetattr(STDIN_FILENO, TCSANOW, &raw);
}

void disableRawMode(struct termios *original)
{
    tcsetattr(STDIN_FILENO, TCSANOW, original);
}

void keyboardManager(int *quit, int *month, int *year)
{
    char c;
    while (1) {
        if (read(STDIN_FILENO, &c, 1) == 1) {
            if (c == 27) { // Escape character
                char seq[2];
                if (read(STDIN_FILENO, &seq[0], 1) == 1 && read(STDIN_FILENO, &seq[1], 1) == 1) {
                    if (seq[0] == '[') {
                        switch (seq[1]) {
                            case 'A':
                            case 'C':
                                *month += 1;
                                if (*month == 13)
                                {
                                    *month = 1;
                                    (*year)++;
                                }
                                return;
                            case 'B':
                            case 'D':
                                *month -= 1;
                                if (*month == 0 && (*year) > 1)
                                {
                                    *month = 12;
                                    (*year)--;
                                }
                                return;
                        }
                    }
                }
            } else if (c == 'q') {
                *quit = 1;
                return;
            }
        }
    }
}