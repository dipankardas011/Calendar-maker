// makeCalendar.h : Include file for standard system include files,
// or project specific include files.

#pragma once
using std::cin;
using std::cout;
using std::endl;
enum monthNames
{
    Jan = 1,
    Feb,
    Mar,
    Apr,
    May,
    Jun,
    Jul,
    Aug,
    Sep,
    Oct,
    Nov,
    Dec
};
/*
Index     Day
0         Sunday
1         Monday
2         Tuesday
3         Wednesday
4         Thursday
5         Friday
6         Saturday * /
/**
 * @def month in class Calendar
 * month is within the range of [1..12]
 * @def day in class Calendar
 * days is within the range of [1..31]
 * @def year in class Calendar
 * year must be less than [1901...2100]
 */
class Calendar
{
private:
    int YEAR;
    int MONTH;
    int DAY;

public:
    Calendar(void);
    void yearInput(int);
    void monthInput(void);
    inline int yearVal(void) { return this->YEAR; }

    inline int monthVal(void) { return this->MONTH; }
    void displayMonth(void);
    
};
inline bool isLeapYear(int yy)
{
    if ((yy % 4 == 0 && yy % 100 != 0) || yy % 400 == 0)
        return true;
    return false;
}
void printMonthName(int);
int lastDayOfMonth(int, int);
void welcomePage(void);
