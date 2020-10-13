#include <bits/stdc++.h>
using namespace std;
const int N = 1010;

int n, t;
int a[N];

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &t);
		printf("%d ", ++a[t]);
	}
	puts("");
	return 0; 
}

