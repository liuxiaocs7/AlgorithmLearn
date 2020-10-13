#include <bits/stdc++.h>
using namespace std;

int days[12][2] = {{31, 31}, {28, 29}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, 
                   {31, 31}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}};

bool is_leap(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int main()
{
    int y, d;
    cin >> y >> d;

    int i = 0;
    int month, day;

    while(d > 0)
    {
        if(d <= days[i][is_leap(y)])
        {
            month = i + 1;
            day = d;
            break;
        }
        else
        {
            d -= days[i][is_leap(y)];
            i++;
        }
    }

    cout << month << endl << day << endl;
    return 0;
}