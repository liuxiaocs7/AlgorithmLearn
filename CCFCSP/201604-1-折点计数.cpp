#include <bits/stdc++.h>
using namespace std;
const int N = 1010;

int n, ans;
int a[N];

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i < n - 1; i++)
	{
		if((a[i] - a[i - 1]) * (a[i] - a[i + 1]) > 0)
			ans++;
	}
	printf("%d\n", ans);
	return 0; 
}

