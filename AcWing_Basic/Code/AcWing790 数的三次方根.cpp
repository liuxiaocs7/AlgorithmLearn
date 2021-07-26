#include <bits/stdc++.h>
using namespace std;

int main()
{
    double x;
    scanf("%lf", &x);
    
    double l = -100, r = 100;
    while(r - l > 1e-8)
    {
        double mid = (l + r) / 2;
        if(mid * mid * mid >= x) r = mid;
        else l = mid;
    }
    
    printf("%.6f\n", l);
    return 0;
}