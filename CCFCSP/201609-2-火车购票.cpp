#include <bits/stdc++.h>
using namespace std;
const int N = 1010;

int n, t;
int a[20];

int main()
{
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &t);
        // 安排相邻位置
        bool arange = false;
        for(int j = 0; j < 20; j++)
        {
            if(a[j] + t <= 5)
            {  
                for(int k = a[j] + 1; k <= a[j] + t; k++)
                    printf("%d ", j * 5 + k);
                a[j] += t;
                arange = true;
                break;
            }
        }

        // 不相邻位置
        if(!arange)
        {
            for(int j = 0; j < 20; j++)
            {
                if(a[j] < 5)
                {  
                    for(int k = a[j] + 1; k <= 5; k++)
                    {
                        printf("%d ", j * 5 + k);
                        a[j] += 1;
                        if(--t <= 0) break;
                    }
                }
                if(t <= 0) break;
            }
        }
        puts("");
    }
    return 0;
}