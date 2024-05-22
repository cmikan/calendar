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

    printf("   %s %d\n", mont_name, year);

    printf(" mo tu we th fr sa su\n");
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
        printf("%*d", 3, i + 1); // i start at 0
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

    // Get current terminal attributes
    tcgetattr(STDIN_FILENO, original);

    // Copy to raw mode
    raw = *original;

    // Modify terminal attributes
    raw.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
    raw.c_cc[VMIN] = 0;  // Minimum number of characters for noncanonical read
    raw.c_cc[VTIME] = 1; // Timeout in deciseconds for noncanonical read

    // Set the new attributes
    tcsetattr(STDIN_FILENO, TCSANOW, &raw);
}

// Function to restore original terminal settings
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
            } else if (c == 'q') { // Exit on 'q' key press
                *quit = 1;
                return;
            }
        }
    }
}