#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
typedef pair<int, int> PII;

int n, m, x, c, l, r;
int a[N], s[N];

vector<int> alls;
vector<PII> add, query;

int find(int x)
{
    int l = 0, r = alls.size() - 1;
    while(l < r)
    {
        int mid = (l + r) >> 1;
        if(alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l + 1;
}

int main()
{
    scanf("%d%d", &n, &m);
    while(n--)
    {
        scanf("%d%d", &x, &c);
        add.push_back({x, c});
        alls.push_back(x);
    }
    while(m--)
    {
        scanf("%d%d", &l, &r);
        query.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    
    for(const auto &item : add)
    {
        int id = find(item.first);
        a[id] += item.second;
    }
    
    for(int i = 1; i <= alls.size(); i++) s[i] = s[i - 1] + a[i];
    
    for(const auto &item : query)
    {
        int l = find(item.first);
        int r = find(item.second);
        printf("%d\n", s[r] - s[l - 1]);
    }
    return 0;
}