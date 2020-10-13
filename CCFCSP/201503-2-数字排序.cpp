#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> mp;

struct node
{
    int key, count;

    bool operator< (const node &t) const
    {
        if(count == t.count) return key > t.key;
        return count < t.count;
    }
};

int main()
{
    int n, t;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &t);
        mp[t]++;
    }

    priority_queue<node> q;
    node no;
    for(const auto &it : mp)
        q.push({it.first, it.second});

    while(!q.empty())
    {
        no = q.top();
        q.pop();
        printf("%d %d\n", no.key, no.count);
    }

    return 0;
}