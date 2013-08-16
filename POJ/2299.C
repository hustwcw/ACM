#include<stdio.h>
#define MAX 500005
int n,t[MAX],a[MAX];
long long sum;
void merge(int l, int mid, int r )
{
    int p = 0;
    int i = l, j = mid + 1;
    while(i <= mid&& j <= r)
    {
        if(a[i] > a[j])
        {
            t[p++] = a[j++];
            sum =sum + mid - i + 1;
        }
        else 
        {
            t[p++] = a[i++];
        }
    }
    while(i <= mid) t[p++] = a[i++];
    while(j <= r) t[p++] = a[j++];
    for(i = 0; i < p; i++)
    {
        a[l + i] = t[i];
    }
}
void mergesort(int l ,int r)
{
    if(l < r)
    {
        int mid = (r - l) / 2 + l;
        mergesort(l , mid);
        mergesort(mid + 1 , r);
        merge(l, mid , r);
    }
}
int main()
{
	int sum;
	int i;
	freopen("c:\\in.txt","r",stdin);
    while(scanf("%d",&n),n)
    {
        sum=0;
        for(i = 0; i < n; i++)
        {
            scanf(" %d ", &a[i]);
        }
        mergesort(0 , n - 1);
        printf("%lld\n", sum);
    }
    return 0;
}