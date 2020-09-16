#include <bits/stdc++.h>
using namespace std;
const int N = 100010;

int a[N];
int n, q, k;

int main()
{
    scanf("%d%d", &n, &q);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    while(q--)
    {
        scanf("%d", &k);
        int l = 0, r = n - 1;
        while(l < r)
        {
            int mid = (l + r >> 1);
            if(a[mid] >= k) r = mid;
            else l = mid + 1;
        }
        
        if(a[l] != k) printf("-1 -1\n");
        else
        {
            printf("%d ", l);
            
            int l = 0, r = n - 1;
            while(l < r)
            {
                int mid = (l + r + 1 >> 1);
                if(a[mid] <= k) l = mid;
                else r = mid - 1;
            }
            printf("%d\n", r);
        }
    }
    return 0;
}