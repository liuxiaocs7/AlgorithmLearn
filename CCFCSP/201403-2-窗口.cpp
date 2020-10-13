#include <bits/stdc++.h>
using namespace std;

struct node
{
    int x1, y1, x2, y2;
    int id;
};

node v[20];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    for(int i = n; i > 0; i--)
    {
        scanf("%d%d%d%d", &v[i].x1, &v[i].y1, &v[i].x2, &v[i].y2);
        v[i].id = n - i + 1;
    }

    while(m--)
    {
        int a, b;
        scanf("%d%d", &a, &b);

        bool is_find = false;
        for(int i = 1; i <= n; i++)
        {
            if(a >= v[i].x1 && b >= v[i].y1 && a <= v[i].x2 && b <= v[i].y2)
            {
                is_find = true;
                printf("%d\n", v[i].id);

                node t = v[i];
                for(int j = i; j > 1; j--)
                    v[j] = v[j - 1];
                v[1] = t;
                break;
            }
        }

        if(!is_find) printf("IGNORED\n");
    }
    return 0;
}