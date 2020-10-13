#include <bits/stdc++.h>
using namespace std;
const int N = 1010;

int n;
pair<int, int> p[N];  // 记录点
map<pair<int, int>, int> mp; 
int cnt[5];  // 得分 0-4 次数 

int main()
{
	scanf("%d", &n);		
	for(int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		p[i] = {a, b};
		mp[p[i]] = 1;  // 已有的点为1，其余情况均会被计算为0 
	}
	
	for(int i = 0; i < n; i++)
	{
		int dx = p[i].first, dy = p[i].second;
		if(mp[{dx + 1, dy}] && mp[{dx - 1, dy}] && mp[{dx, dy + 1}] && mp[{dx, dy - 1}])
			cnt[mp[{dx + 1, dy + 1}] + mp[{dx + 1, dy - 1}] + mp[{dx - 1, dy + 1}] + mp[{dx - 1, dy - 1}]]++;
	}
	for(int i = 0; i < 5; i++)
		printf("%d\n", cnt[i]);
	return 0;
}