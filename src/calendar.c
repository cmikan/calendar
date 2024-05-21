#include <stdio.h>
#include "day_utils.h"
#include "display_utils.h"

int main (int argc, char **argv)
{
    if (!check_date(1, 2, 2024))
    {
        return -1;
    }
    draw_calendar(5, 2024);
    return 0;
}