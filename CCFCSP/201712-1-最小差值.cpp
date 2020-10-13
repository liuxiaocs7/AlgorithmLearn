#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, ans = 1e8;
int a[N];

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++) 
		scanf("%d", &a[i]);
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(abs(a[i] - a[j]) < ans)
				ans = abs(a[i] - a[j]);
		}
	}
	printf("%d\n", ans);
	return 0; 
}

