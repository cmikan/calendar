#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>

#include "day_utils.h"

int draw_calendar(int day, int month, int year)
{
    int line_nb = 0;
    int nb_days = 0;
    char *mont_name;
    month_name(month, &mont_name);
    
    nb_days = day_in_month(month, year);

    printf("   \033[31m\033[1m%s %d\033[0m\n", mont_name, year);

    printf("\033[93m\033[1m mo tu we th fr sa su\033[0m\n");
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
            if (day - 1 == i)
            {
                before = " \033[31m\033[1m\033[43m";
                after = "\033[0m";
            }
            else
            {
                before = " \033[31m";
                after = "\033[0m";
            }
        }
        else
        {
            if (day - 1 == i)
            {
                before = " \033[1m\033[43m";
                after = "\033[0m";
            }
            else
            {
                before = " ";
                after = "";
            }
        }

        printf("%s%*d%s", before, 2, i + 1, after);
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

void keyboardManager(int *quit, int *day, int *month, int *year)
{
    char c;
    while (1) {
        if (read(STDIN_FILENO, &c, 1) == 1)
        {
            switch (c)
            {
                case 27: // Escape character
                {
                    char seq[2];
                    if (read(STDIN_FILENO, &seq[0], 1) == 1 && read(STDIN_FILENO, &seq[1], 1) == 1) 
                    {
                        if (seq[0] == '[') 
                        {
                            switch (seq[1]) 
                            {
                                case 'A': // Up arrow
                                {
                                    *day -= 7;
                                    if (*day < 1)
                                    {
                                        *day = 1;
                                    }
                                    return;
                                }
                                case 'B': // Down arrow
                                {
                                    *day += 7;
                                    int tmp = day_in_month(*month, *year);
                                    if (*day > tmp)
                                    {
                                        *day = tmp;
                                    }
                                    return;
                                }
                                case 'C': // Right arrow
                                {
                                    *day += 1;
                                    int tmp = day_in_month(*month, *year);
                                    if (*day > tmp)
                                    {
                                        *day = tmp;
                                    }
                                    return;
                                }
                                case 'D': // Left arrow
                                {
                                    *day -= 1;
                                    if (*day < 1)
                                    {
                                        *day = 1;
                                    }
                                    return;
                                }
                            }
                        }
                    }
                }
                case 'p':
                {
                    *month += 1;
                    if (*month == 13)
                    {
                        *month = 1;
                        (*year)++;
                    }
                    return;
                }
                case 'o':
                {
                    *month -= 1;
                    if (*month == 0 && (*year) > 1)
                    {
                        *month = 12;
                        (*year)--;
                    }
                    else if (*month == 0)
                    {
                        *month = 1;
                    }
                    return;
                }
                case 'q':
                {
                    *quit = 1;
                    return;
                }
            }
        }
    }
}