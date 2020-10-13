#include <bits/stdc++.h>
using namespace std;
const int N = 110;
typedef pair<int, int> PII;

int g[N][N], d[N][N];
int n, m;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

int bfs()
{
    memset(d, -1, sizeof d);
    queue<PII> q;
    q.push({1, 1});
    d[1][1] = 0;
    
    while(!q.empty())
    {

        PII t = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int x = t.first + dx[i];
            int y = t.second + dy[i];
            if(x >= 1 && x <= n && y >= 1 && y <= m && g[x][y] == 0 && d[x][y] == -1)
            {
                q.push({x, y});
                d[x][y] = d[t.first][t.second] + 1;
            }
        }
    }
    return d[n][m];
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &g[i][j]);
    printf("%d\n", bfs());
    return 0;
}