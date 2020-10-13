#include <bits/stdc++.h>
using namespace std;

int r, g, y, n, k, t, sum;

int main()
{
	scanf("%d%d%d%d", &r, &y, &g, &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d%d", &k, &t);
		if(k == 0 || k == 1) sum += t;
		else if(k == 2) sum += t + r;
	}
	
	printf("%d\n", sum);
	return 0; 
}

//30 3 30
//8
//0 10
//1 5
//0 11
//2 2
//0 6
//0 3
//3 10
//0 3
