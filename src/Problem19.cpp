#include <iostream>

#include "Problems.h"

// You are given the following information, but you may prefer to do some research for yourself.
// 
// * 1 Jan 1900 was a Monday.
// * Thirty days has September,
//   April, June and November.
//   All the rest have thirty - one,
//   Saving February alone,
//   Which has twenty - eight, rain or shine.
//   And on leap years, twenty - nine.
// * A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
//
//   How many Sundays fell on the first of the month during the twentieth century(1 Jan 1901 to 31 Dec 2000) ?

static const int DaysPerMonth[12] =
{
    31, // Jan
    28, // *Feb
    31, // Mar
    30, // Apr
    31, // May
    30, // Jun
    31, // Jul
    31, // Aug
    30, // Sep
    31, // Oct
    30, // Nov
    31, // Dec
};

enum class DayOfWeek : int
{
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
};

constexpr bool IsLeapYear(int year)
{
    if((year % 4) == 0)
    {
        // Leap year (unless century not devisible by 400)
        if (0 == (year % 100))
        {
            // Century, return true only if divisibly by 400
            return(0 == (year % 400));
        }

        return true;
    }

    return false;
}

constexpr DayOfWeek NextDayOfWeek(DayOfWeek dow)
{
    switch (dow)
    {
    case DayOfWeek::Sunday:
        return DayOfWeek::Monday;
    case DayOfWeek::Monday:
        return DayOfWeek::Tuesday;
    case DayOfWeek::Tuesday:
        return DayOfWeek::Wednesday;
    case DayOfWeek::Wednesday:
        return DayOfWeek::Thursday;
    case DayOfWeek::Thursday:
        return DayOfWeek::Friday;
    case DayOfWeek::Friday:
        return DayOfWeek::Saturday;
    default:
    case DayOfWeek::Saturday:
        return DayOfWeek::Sunday;
    }
}

constexpr int DaysInMonth(int Month, int Year)
{
    int days = DaysPerMonth[Month - 1];
    if(Month == 2 && IsLeapYear(Year))
        days++;
    return days;
}

struct Date
{
    Date(int year, int month, int day) :
        Year(year),
        Day(day),
        Month(month) {}

    int Year;
    int Month;
    int Day;

    Date NextDay()
    {
        int NextYear = Year;
        int NextMonth = Month;
        int NextDay = Day + 1;
        if (NextDay == DaysInMonth(Month, Year) + 1)
        {
            NextDay = 1;
            NextMonth++;
            if (NextMonth == 12 + 1)
            {
                NextMonth = 1;
                NextYear++;
            }
        }
        return Date(NextYear, NextMonth, NextDay);
    }

    bool operator==(const Date& o) const
    {
        return Year == o.Year &&
            Month == o.Month &&
            Day == o.Day;
    }

    bool operator!=(const Date& o) const
    {
        return !operator==(o);
    }
};

void CProblem<19>::Execute()
{
    int NumFirstDaySundays = 0;
    DayOfWeek dow = DayOfWeek::Monday;
    for (Date date(1900, 1, 1); date != Date(2000, 12, 2); date = date.NextDay())
    {
        if (date.Year > 1900 && date.Day == 1 && dow == DayOfWeek::Sunday)
        {
            std::cout << date.Year << "/" << date.Month << "/" << date.Day << std::endl;
            NumFirstDaySundays++;
        }
        dow = NextDayOfWeek(dow);
    }
    std::cout << "Problem 18 Solution: " << NumFirstDaySundays << std::endl;
}