#include <bits/stdc++.h>
using namespace std;
const int N = 1010;

int n, k;
unordered_set<int> out;

int main()
{
    scanf("%d%d", &n, &k);

    int t = n, cnt = 0;
    while(t != 1)
    {
        for(int i = 1; i <= n; i++)
        {
            if(!out.count(i))
            {
                cnt++;
                if(cnt % k == 0 || cnt % 10 == k)
                {
                    out.insert(i);
                    t--;
                    if(t == 1) break;
                }
            }
        }
    }

    int win = -1;
    for(int i = 1; i <= n; i++)
        if(!out.count(i)) win = i;
    printf("%d\n", win);
    return 0;
}