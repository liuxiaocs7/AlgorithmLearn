#include <bits/stdc++.h>
using namespace std;

int n, ans, t;
unordered_set<int> st;

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &t);
		if(st.count(-t)) ans++;
		else st.insert(t);
	}
	printf("%d\n", ans);
	return 0; 
}

