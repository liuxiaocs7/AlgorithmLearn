#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, m;
int v[N], w[N], f[N];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d%d", &v[i], &w[i]);
        
    for(int i = 1; i <= n; i++)
    {
        for(int j = m; j >= v[i]; j--)
        {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    printf("%d\n", f[m]);
    return 0;
}