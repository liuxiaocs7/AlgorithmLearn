#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

int a[N], temp[N];
int n;

ll merge_sort(int a[], int l, int r)
{
    if(l >= r) return 0;
    
    int mid = (l + r) >> 1;
    
    ll ans = merge_sort(a, l, mid) + merge_sort(a, mid + 1, r);
    
    int k = 0, i = l, j = mid + 1;
    while(i <= mid && j <= r)
    {
        if(a[i] <= a[j]) temp[k++] = a[i++];
        else
        {
            temp[k++] = a[j++];
            ans += (mid - i + 1);
        }
    }
    
    while(i <= mid) temp[k++] = a[i++];
    while(j <= r) temp[k++] = a[j++];
    
    for(int i = l, j = 0; i <= r; i++, j++)
        a[i] = temp[j];
        
    return ans;
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    ll ans = merge_sort(a, 0, n - 1);
    printf("%lld\n", ans);
    return 0;
}