#include <bits/stdc++.h>
using namespace std;

bool judge(int x)
{
	if(x % 7 == 0)
		return true;
	while(x)
	{
		int t = x % 10;
		if(t == 7) return true;
		x /= 10; 
	}
	return false;
}

int cnt[4] = {0};
int n;

int main()
{
	scanf("%d", &n);
	for(int i = 0, t = 1; i < n; t++)
	{
		if(judge(t))
			cnt[(t - 1) % 4]++;	
		else
			i++;	
	}
	
	for(int i = 0; i < 4; i++)
		printf("%d\n", cnt[i]);
	return 0;
} 