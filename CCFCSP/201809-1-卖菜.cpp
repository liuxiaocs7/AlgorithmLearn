#include <bits/stdc++.h>
using namespace std;
const int N = 1010;

int n;
int a[N], b[N];

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	b[0] = (a[0] + a[1]) / 2;
	b[n - 1] = (a[n - 1] + a[n - 2]) / 2;
	for(int i = 1; i < n - 1; i++)
		b[i] = (a[i] + a[i - 1] + a[i + 1]) / 3;
	for(int i = 0; i < n; i++)
		printf("%d ", b[i]);
	puts("");	
	return 0; 
}