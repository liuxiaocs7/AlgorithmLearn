#include <bits/stdc++.h>
using namespace std;
const int N = 1000000 + 10;

int n, ans;
int cnt[N];

// 在一个数轴上以柱状图的方式表示出来 

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n * 2; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		for(int j = a; j < b; j++)
			cnt[j]++;
	}
	
	for(int i = 1; i <= N; i++)
	{
		if(cnt[i] == 2) 
			ans++;
	}
	printf("%d\n", ans);
	
	return 0; 
}

//4
//1 3
//5 6
//9 13
//14 15
//2 4
//5 7
//10 11
//13 14
