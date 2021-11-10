#include <iostream>
#include <cstring>
using namespace std;

int n, m, s, r;
int par[131072], rnk[131072];
int px[1048576], py[1048576];
bool gg[1048576];

int getpar(int cur)
{
    if (par[cur] == -1)
    {
        return cur;
    }
    return par[cur] = getpar(par[cur]);
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
        if (rnk[a] == rnk[b])
        {
            ++rnk[b];
        }
    }
}

bool check(int lim)
{
    int i, a, b;
    memset(par, -1, sizeof(par));
    memset(rnk, 0, sizeof(rnk));
    lim = m + (lim+1) * s;
    for (i=0; i<lim; i++)
    {
        if (i >= m && gg[(i-m)/s])
        {
            continue;
        }
        a = px[i];
        b = py[i];
        merge(a, b+n);
        merge(b, a+n);
        if (getpar(a) == getpar(b))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int i, j, ans, p, q, mid;
    while (scanf("%d%d", &n, &m) == 2)
    {
        memset(gg, 0, sizeof(gg));
        for (i=0; i<m; i++)
        {
            scanf("%d%d", &px[i], &py[i]);
        }
        scanf("%d%d", &r, &s);
        for (i=0; i<r; i++)
        {
            for (j=0; j<s; j++)
            {
                scanf("%d%d", &px[m+i*s+j], &py[m+i*s+j]);
            }
        }
        for (i=0, j=0; i<3; i++)
        {
            ans = -1;
            for (p=j, q=r-1; p<=q; )
            {
                mid = ((p+q)>>1);
                if (check(mid))
                {
                    ans = mid;
                    q = mid - 1;
                }
                else
                {
                    p = mid + 1;
                }
            }
            if (ans == -1)
            {
                break;
            }
            gg[ans] = true;
            printf("%d\n", ans+1);
            j = ans + 1;
        }
    }
    return 0;
}
