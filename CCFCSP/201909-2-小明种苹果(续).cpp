#include <bits/stdc++.h>
using namespace std;
const int N = 1010;

int n, m, t, d, e, temp;
bool lost[N];
 
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &m);
		
		// 第一个数是数个数 
		int sum = 0;
		scanf("%d", &sum);
		for(int j = 1; j < m; j++)
		{
			scanf("%d", &temp);
			if(temp <= 0) sum += temp;
			else
			{
				if(sum > temp) lost[i] = true; // 掉落
				sum = temp;	
			}
		}
		t += sum; 
	}
	
	for(int i = 0; i < n; i++)
	{
		if(lost[i]) d++;
		if(lost[i] && lost[(i + 1) % n] && lost[(i + 2) % n]) e++;
	}
	
	printf("%d %d %d\n", t, d, e);
	return 0; 
}


// 测试用例
//4
//4 74 -7 -12 -5
//5 73 -8 -6 59 -4
//5 76 -5 -10 60 -2
//5 80 -6 -15 59 0