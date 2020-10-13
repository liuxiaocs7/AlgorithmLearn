#include <bits/stdc++.h>
using namespace std;

set<pair<int, int>> st;
int n;

int main()
{
    scanf("%d", &n);
    int x1, y1, x2, y2;
    while(n--)
    {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

        for(int i = x1; i < x2; i++)
        {
            for(int j = y1; j < y2; j++)
            {
                st.insert({i, j});
            }
        }
    }

    printf("%d\n", st.size());
    return 0;
}