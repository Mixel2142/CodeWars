/*
https://www.codewars.com/kata/target-date/cpp
You have an amount of money a0 > 0 and you deposit it with a constant interest rate of p% > 0 per year on the 1st of January 2016. You want to have an amount a >= a0.
#Task: The function date_nb_days (or dateNbDays...) with parameters a0, a, p will return, as a string, the date on which you have just reached a.
#Example: date_nb_days(100, 101, 0.98) --> "2017-01-01" (366 days)
date_nb_days(100, 150, 2.00) --> "2035-12-26" (7299 days)
#Notes:
The return format of the date is "YYYY-MM-DD"
The deposit is always on the "2016-01-01"
If p% is the rate for a year the rate for a day is p divided by 36000 since banks consider that there are 360 days in a year.
You have: a0 > 0, p% > 0, a >= a0
*/
#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <cmath>
using namespace std;

void DatePlusDays(struct tm* date, int days)
{
    const time_t ONE_DAY = 24 * 60 * 60;
    time_t date_seconds = mktime( date ) + (days * ONE_DAY);
    *date = *localtime(&date_seconds);
}

string dateNbDays(double a0, double a, double p)
{
    struct tm date = { 0, 0, 12 };
    int year = 2016; int month = 1; int day = 1;
    date.tm_year = year - 1900;
    date.tm_mon = month - 1;
    date.tm_mday = day;
    int r = static_cast<int>(std::ceil(std::log(a / a0) / std::log(1 + p / 36000.0)));
    DatePlusDays(&date, r);
    std::ostringstream oss;
    oss << std::put_time(&date, "%Y-%m-%d");
    auto str = oss.str();
    return str;
}

void main(int n1,int n2,int n3)
{
cout<<endl<<dateNbDays( n1, n2, n3);
}