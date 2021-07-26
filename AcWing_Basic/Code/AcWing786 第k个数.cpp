#include <bits/stdc++.h>
using namespace std;
const int N = 100010;

int a[N];
int n, k;

int quick_sort(int a[], int l, int r, int k)
{
    if(l >= r) return a[l];
    int x = a[l + r >> 1], i = l - 1, j = r + 1;
    while(i < j)
    {
        do i++; while(a[i] < x);
        do j--; while(a[j] > x);
        if(i < j) swap(a[i], a[j]);
    }

    if(j - l + 1 >= k) return quick_sort(a, l, j, k);
    else return quick_sort(a, j + 1, r, k - (j - l + 1));
}

int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int ans = quick_sort(a, 0, n - 1, k);
    printf("%d\n", ans);
    return 0;
}