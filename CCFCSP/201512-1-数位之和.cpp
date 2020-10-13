#include <bits/stdc++.h>
using namespace std;

int n, ans;

int main()
{
	scanf("%d", &n);
	while(n)
	{
		ans += n % 10;
		n /= 10;
	}
	printf("%d\n", ans);
	return 0; 
}

