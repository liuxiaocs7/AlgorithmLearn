#include <bits/stdc++.h>
using namespace std;
const int N = 10010;

int n, t, ans, max_t;
int a[N];

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &t);
		a[t]++;
	}
	
	for(int i = 0; i < N; i++)
	{
		if(a[i] > max_t)
		{
			max_t = a[i];
			ans = i;
		}
	}
	printf("%d\n", ans);
	return 0; 
}

