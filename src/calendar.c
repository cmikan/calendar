#include <stdio.h>
#include <time.h>
#include <string.h>
#include "day_utils.h"
#include "display_utils.h"

int main (int argc, char **argv)
{
    int day;
    int month;
    int year;

    if (argc == 1) // No argument
    {
        time_t t = time(NULL);
        struct tm *tm = localtime(&t);

        year = tm->tm_year+1900;
        month = tm->tm_mon + 1;
        day = tm->tm_mday;
    }
    else if (argc == 2)
    {
        if (strcmp("--help", argv[1]) == 0)
        {
            printf("Usage: %s (<dd/mm/year>)\n", argv[0]);
            return 0;
        }
        else if (sscanf(argv[1], "%2d/%2d/%4d", &day, &month, &year) != 3)
        {
            fprintf(stderr, "Invalid date formatting. Expected format : dd/mm/yyyy");
            return -1;
        }
    }
    else
    {
        fprintf(stderr, "Usage: %s (<dd/mm/year>)\n", argv[0]);
            return -1;
    }

    if (!check_date(day, month, year))
    {
        return -1;
    }
    draw_calendar(month, year);
    return 0;
}