#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    string num = s.substr(0, 11);
    char idx = s[12];

    int i = 1, sum = 0;
    for(const auto &it : num)
    {
        if(it >= '0' && it <= '9')
            sum += ((it - '0') * (i++));
    }

    int res = sum % 11;
    char ans;
    if(res == 10) ans = 'X';
    else ans = '0' + res; 

    if(ans == idx) cout << "Right" << endl;
    else
    {
        cout << num << "-";
        if(sum % 11 == 10)
            cout << "X\n";
        else
            cout << sum % 11 << endl;
    }
    return 0;
}