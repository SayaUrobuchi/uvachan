#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int N = 1000005;

int ary[N], lhand[N], rhand[N], tmp[N];

void merge(int p, int q)
{
    int mid, i, j, k, l, r;
    mid = ((p+q)>>1);
    for (i=p, j=mid+1, k=p, l=0, r=q-mid; k<=q; k++)
    {
        if (j > q || (i <= mid && ary[i] < ary[j]))
        {
            tmp[k] = ary[i++];
            rhand[tmp[k]] += r;
            l++; 
        }
        else
        {
            tmp[k] = ary[j++];
            lhand[tmp[k]] += l;
            r--;
        }
    }
    for (k=p; k<=q; k++) 
    {
        ary[k] = tmp[k];
    }
}

void msort(int p, int q)
{
    int mid;
    if (p == q)
    {
        return;
    }
    mid = ((p+q)>>1);
    msort(p, mid);
    msort(mid+1, q);
    merge(p, q); 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, i;
    long long ans;
    while (scanf("%d", &n) == 1)
    {
        for (i=0; i<n; i++)
        {
            scanf("%d", &ary[i]);
            lhand[i] = 0;
            rhand[i] = 0;
        }
        msort(0, n-1);
        for (i=0, ans=0; i<n; i++)
        {
            ans += lhand[i] * (long long)rhand[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}

