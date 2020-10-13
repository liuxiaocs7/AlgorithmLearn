#include <bits/stdc++.h>
using namespace std;

int n;
int sum; // 总得分
int last;  // 上一次得分得
 
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		if(n == 0) break;		
		if(n == 1)
		{
			last = 1;
			sum += 1;
		}
		else if(n == 2 && (last == 0 || last == 1))
		{
			last = 2;
			sum += 2;
		}
		else
		{
			last += 2; 
			sum += last;
		}
	}
	printf("%d\n", sum);
	return 0; 
}