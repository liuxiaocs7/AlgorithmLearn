#include <bits/stdc++.h>
using namespace std;
const int N = 40;

int n, m;
int a[N][N];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m - 2; j++)
        {
            if(abs(a[i][j]) == abs(a[i][j+1]) && abs(a[i][j+1]) == abs(a[i][j+2]))
            {
                if(a[i][j] > 0) a[i][j] = -a[i][j];
                if(a[i][j+1] > 0) a[i][j+1] = -a[i][j+1];
                if(a[i][j+2] > 0) a[i][j+2] = -a[i][j+2];
            }
        }
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n - 2; j++)
        {
            if(abs(a[j][i]) == abs(a[j+1][i]) && abs(a[j+1][i]) == abs(a[j+2][i]))
            {
                if(a[j][i] > 0) a[j][i] = -a[j][i];
                if(a[j+1][i] > 0) a[j+1][i] = -a[j+1][i];
                if(a[j+2][i] > 0) a[j+2][i] = -a[j+2][i];
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i][j] < 0) printf("0 ");
            else printf("%d ", a[i][j]);
        }
        puts("");
    }
    return 0;
}