#include <bits/stdc++.h>
using namespace std;

int n, k, ans, t, temp;

int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &t);
		temp += t;
		if(temp >= k)
		{
			temp = 0;
			ans++;
		}
	}
	printf("%d\n", temp > 0 ? ans + 1 : ans);
	return 0; 
}

