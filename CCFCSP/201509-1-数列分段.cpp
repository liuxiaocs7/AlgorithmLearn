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
	for(int i = 0; i < n; )
	{
		int j = i;
		while(a[j] == a[i])
			j++;
		ans++;
		i = j;
	}
	printf("%d\n", ans);
	return 0; 
}

