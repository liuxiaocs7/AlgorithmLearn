#include <bits/stdc++.h>
using namespace std;
const int N = 1010;

int n, m;
int a[N];

int main()
{
    scanf("%d%d", &n, &m);

    for(int i = 1; i <= n; i++)
        a[i] = i;

    while(m--)
    {
        int id, dis;
        scanf("%d%d", &id, &dis);

        int idx = -1;
        for(int i = 1; i <= n; i++)
            if(a[i] == id)
            {
                idx = i;
                break;
            }
        
        if(dis < 0)  // idx位置的数左移dis个
        {
            dis = -dis;
            int t = a[idx];
            for(int j = 0; j < dis; j++)
                a[idx - j] = a[idx - j - 1];
            a[idx - dis] = t;

        }
        else  // idx位置的数右移dis个
        {
            int t = a[idx];
            for(int j = 0; j < dis; j++)
                a[idx + j] = a[idx + j + 1];
            a[idx + dis] = t;
        }
    }

    for(int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    return 0;
}