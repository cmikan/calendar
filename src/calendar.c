#include <stdio.h>
#include "day_utils.h"

int main (int argc, char **argv)
{
    char *day;
    int result = weekday(20, 5, 2024);
    //printf("%d\n", result);
    switch(result)
    {
        case 0:
            day = "Monday";
            break;
        case 1:
            day = "Tuesday";
            break;
        case 2:
            day = "Wednesday";
            break;
        case 3:
            day = "Thursday";
            break;
        case 4:
            day = "Friday";
            break;
        case 5:
            day = "Saturday";
            break;
        case 6:
            day = "Sunday";
            break;

    }
    printf("It's a %s\n", day);
    return 0;
}