/*
** C_Lib PROJECT, 2020
** format_day.c
** File description:
** File that will format givent time to a valid time
** Author:
** Arnaud Guerout
** https://github.com/Guerout-Arnaud
** Contributors:
**
*/

#include <time.h>
#include "constant.h"

static void format_hour(struct tm *time)
{
    if (time->tm_hour < -1 || time->tm_hour > 23)
        if (time->tm_hour > 24)
            time->tm_hour %= 24;
        else
            time->tm_hour = -1;

    if (time->tm_min < -1 || time->tm_min > 59)
        if (time->tm_min > 59)
            time->tm_min %= 59;
        else
            time->tm_min = -1;

    if (time->tm_sec < -1 || time->tm_sec > 59)
        if (time->tm_sec > 59)
            time->tm_sec %= 59;
        else
            time->tm_sec = -1;
    return;
}

static int format_month_day(struct tm *time)
{
    if (time->tm_mday < 0 || time->tm_mday > 31)
        if (time->tm_mday > 31)
            time->tm_mday = (time->tm_mday % 31) + 1;
        else
            time->tm_mday = 0;
    if (time->tm_mday > 28 && time->tm_mday == 2 && (time->tm_year % 4) != 0) {
        return (ERROR);
    } else if (time->tm_mday > 30) {
        if (time->tm_mon <= JULY && (time->tm_mon % 2) == 0)
            return (ERROR);
        else if (time->tm_mon >= AUGUST && (time->tm_mon % 2) == 1)
            return (ERROR);
    }
    return (SUCCESS);
}

static int dayofweek(int day, int month, int year)
{
    static int translator[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    int weekday = 0;

    if (day == 0 || month == 0 || year == 0)
        return (ERROR);

    year -= month < 3;
    weekday = (year + (year / 4) - (year / 100) + (year / 400) +
        translator[month - 1] + day) % 7;
    if (weekday == 0)
        weekday += 7;
    return (weekday);
}

int format_time(struct tm *time)
{
    int weekday = 0;

    format_month_day(time);
    if (time->tm_mon < 0 || time->tm_mon > DECEMBER)
        if (time->tm_mon > DECEMBER)
            time->tm_mon = (time->tm_mon % DECEMBER) + JANUARY;
        else
            time->tm_mon = ALL;

    if (time->tm_wday < ALL || time->tm_wday > SUNDAY)
        if (time->tm_wday > SUNDAY) {
            time->tm_wday = (time->tm_wday % SUNDAY) + MONDAY;
        }
        else
            time->tm_wday = ALL;
    weekday = dayofweek(time->tm_mday, time->tm_mon, time->tm_year);
    if (weekday != ERROR && time->tm_wday != weekday)
        return (ERROR);
    format_hour(time);
    return;
}