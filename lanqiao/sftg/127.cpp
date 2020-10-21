
#include <iostream>

using namespace std;

bool isCurRun;
int maxDay;
int maxMonth = 12;
int y, m, d;

int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct date
{
    /* data */
    int year;
    int month;
    int day;
    date(int y, int m, int d) : year(y), month(m), day(d) {}
};

bool isRun(int a)
{
    return a % 400 == 0 || (a % 4 == 0 && a % 100 != 0);
}

int days(int year, int month, int day)
{
    int res = 0;
    for (int i = 0; i < month - 1; i++)
    {
        if (i != 1)
        {
            res += daysPerMonth[i];
        }
        else
        {
            res += isRun(year) ? 29 : 28;
        }
    }
    res += day - 1;
    return res;
}

int dayDistance(date a, date b)
{
    int res = 0;

    for (int i = a.year + 1; i < b.year; i++)
    {
        res += isRun(i) ? 366 : 365;
    }
    
    int aToEnd = 365 + isRun(a.year) - days(a.year, a.month, a.day);
    int beginTob = days(b.year, b.month, b.day);
    cout << "a: " << aToEnd << " b: " << beginTob << endl;

    return res + ((b.year == a.year) ? (aToEnd + beginTob - isRun(a.year) - 365) : aToEnd + beginTob);

}

int main(int argc, char const *argv[])
{

    cin >> y >> m >> d;

    bool less = true;
    if(2011 > y) less = false;
    else if(2011 == y)
        if(11 > m) less = false;
        else if(11 == m)
            if(11 > d) less = false;
    
    int num = 0;
    if(less)
        num = dayDistance(date(2011, 11, 11), date(y, m, d));
    else
        num = - dayDistance(date(y, m, d), date(2011, 11, 11));

    cout <<"num: " << num << endl;

    


    cout << days(2011, 11, 11) << endl; 

    cout << days(y, m, d) << endl; 

    return 0;
}
