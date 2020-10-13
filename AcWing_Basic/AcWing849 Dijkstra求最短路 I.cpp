#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
 
const int N = 510;
int n, m;
int g[N][N]; // 邻接矩阵
int dist[N];  // 从1号点到其余点的最短距离
bool st[N];

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);  // 距离初始化为无穷大
    dist[1] = 0;  // 从结点1开始
    for(int i = 0; i < n; i++)
    {
        // 找到dist[t] 为dist数组中最小的
        int t = -1;
        for(int j = 1; j <= n; j++)
            if(!st[j] && (t==-1 || dist[t]>dist[j]))  // 没有确定最短路  在st==false的点中找一个dist最小的点
                t = j;
        if(t == n) break; // 已经找到最短距离了
	    st[t] = true;  // 加入集合，标记已经访问
        for(int j = 1; j <= n; j++)
            dist[j] = min(dist[j], dist[t]+g[t][j]);
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main()
{
 	scanf("%d%d", &n, &m);
    memset(g, 0x3f, sizeof g);
    
    while(m--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);  // 可能产生重边，选一个最小的
    }
    int t = dijkstra();
    printf("%d\n", t);
    return 0;
} 