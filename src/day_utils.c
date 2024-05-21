int is_bissextile(int year)
{
    int return_value = 0;
    if (year > 1582) // Gregorian calendar
    {
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        {
            return_value = 1;
        }
    }
    else // Julian calendar
    {
        if (year % 4 == 0)
        {
            return_value = 1;
        }
    }
    return return_value;
}

int weekday(int day, int month, int year)
{
    int day_index = 4; // The day before the 01/01/0001, if it make sens

    // Day
    day_index += day;

    // Month
    day_index += 31 * (month - 1);

    switch (month)
    {
        case 12:
            day_index--;
        case 11:
        case 10:
            day_index--;
        case 9:
        case 8:
        case 7:
            day_index--;
        case 6:
        case 5:
            day_index--;
        case 4:
        case 3:
            if (is_bissextile(year))
            {
                day_index -= 2;
            }
            else
            {
                day_index -= 3;
            }
            break;
    }

    // Year
    day_index += 365*(year-1);
    if (year > 1582)
    {
        day_index += (year-1) / 4;
        day_index -= (year-1) / 100;
        day_index += (year-1) / 400;
        day_index += 2;
    }
    else
    {
        day_index += (year-1)/4;
    }

    day_index %= 7;
    return day_index;
}