#include <bits/stdc++.h>
using namespace std;

int n, a, b, ans;

int main()
{
	scanf("%d%d", &n, &a);
	for(int i = 1; i < n; i++)
	{
		scanf("%d", &b);
		ans = max(ans, abs(a - b));
		a = b;
	}
	printf("%d\n", ans);
	return 0; 
}

