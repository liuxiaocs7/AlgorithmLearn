#include <bits/stdc++.h>
using namespace std;

int n, ans;

int main()
{
	scanf("%d", &n);
	while(n >= 50)
	{
		ans += 7;
		n -= 50;
	}
	while(n >= 30)
	{
		ans += 4;
		n -= 30;
	}
	while(n >= 10)
	{
		ans++;
		n -= 10;
	}
	printf("%d\n", ans);
	return 0; 
}

