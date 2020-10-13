#include <bits/stdc++.h>
using namespace std;
const int N = 1010;

int nums[N] = {0}; // 蔬果数量 
int n, m, sum;

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= m; j++)  // m + 1
		{
			int t;
			scanf("%d", &t);
			if(j)
				nums[i] -= t; 
			sum += t;
		}
	}
	
	printf("%d", sum);
	int max_v = 0, max_idx = -1;
	for(int i = 0; i < n; i++)
	{
		if(nums[i] > max_v)
		{
			max_v = nums[i];
			max_idx = i;
		}
	}
	printf(" %d %d\n", max_idx + 1, nums[max_idx]);
	return 0;
} 