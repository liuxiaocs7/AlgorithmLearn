#include <bits/stdc++.h>
using namespace std;
const int N = 1010;

int n, s, m, e, t; // start, middle, end 
bool flag;

int main()
{
	scanf("%d", &n);
	if(n % 2 == 0) flag = true; 
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &t);
		if(i == 0) s = t;
		if(flag && i == (n - 1) / 2) m += t;
		if(i == n / 2) m += t; 
		if(i == n - 1) e = t;
	}
	if(s < e) swap(s, e);
	if(flag && m % 2 != 0)
		printf("%d %.1f %d\n", s, m / 2.0, e);
	else if(flag)
		printf("%d %d %d\n", s, m / 2, e);
	else  // 奇数个数 
		 printf("%d %d %d\n", s, m, e);
	return 0;
} 