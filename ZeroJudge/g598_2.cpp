#include <iostream>
#include <cstring>
using namespace std;

int n, m, s, r, k;
int par[131072], rnk[131072];
int rec[131072];

int getpar(int cur)
{
    while (par[cur] != -1)
    {
        cur = par[cur];
    }
    return cur;
}

void merge(int a, int b)
{
    a = getpar(a);
    b = getpar(b);
    if (a != b)
    {
        if (rnk[a] > rnk[b])
        {
            swap(a, b);
        }
        par[a] = b;
        rec[k++] = a;
        if (rnk[a] == rnk[b])
        {
            ++rnk[b];
        }
    }
}

int main()
{
    int i, j, a, b;
    bool gg;
    while (scanf("%d%d", &n, &m) == 2)
    {
        memset(par, -1, sizeof(par));
        memset(rnk, 0, sizeof(rnk));
        for (i=0; i<m; i++)
        {
            scanf("%d%d", &a, &b);
            merge(a, b+n);
            merge(b, a+n);
        }
        scanf("%d%d", &r, &s);
        for (i=0; i<r; i++)
        {
            k = 0;
            for (j=0, gg=false; j<s; j++)
            {
                scanf("%d%d", &a, &b);
                if (!gg)
                {
                    merge(a, b+n);
                    merge(b, a+n);
                    if (getpar(a) == getpar(b))
                    {
                        gg = true;
                    }
                }
            }
            if (gg)
            {
                printf("%d\n", i+1);
                for (j=k-1; j>=0; j--)
                {
                    par[rec[j]] = -1;
                }
            }
        }
    }
    return 0;
}
