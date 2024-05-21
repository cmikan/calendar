#include <stdio.h>
#include "day_utils.h"

void draw_calendar(int month, int year)
{
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
        }
        printf("%*d", 3, i + 1); // i start at 0
    }
    printf("\n");
}