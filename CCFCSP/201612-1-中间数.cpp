#include <bits/stdc++.h>
using namespace std;
const int N = 1010;

int n, t;
int a[N];

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int mid = a[n / 2];
	int l = 0, r = 0;
	for( ; l < n && a[l] < mid; l++);
	for(int i = n - 1; i >= 0 && a[i] > mid; i--, r++);
	printf("%d\n", l == r ? mid : -1);
	return 0; 
}

