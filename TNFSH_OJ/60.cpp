#include <stdio.h>
#include <string.h>
#include <algorithm>

#define M 100005
#define N 5005

int idx[M], st[M], ed[M], w[M], par[N];

bool comp(int p, int q)
{
	return w[p] < w[q];
}

int find(int n)
{
	if (par[n] < 0)
	{
		return n;
	}
	return par[n] = find(par[n]);
}

int main()
{
	int n, m, o, i, j, k, p, q, ans;
	scanf("%d%d%d", &n, &m, &o);
	if (o < 0)
	{
		o = n;
	}
	for (i=0; i<m; i++)
	{
		idx[i] = i;
		scanf("%d%d%d", &st[i], &ed[i], &w[i]);
	}
	std::sort(idx, idx+m, comp);
	memset(par, -1, sizeof(par));
	ans = 0;
	for (i=0, j=(n-1)-(o>1?o-1:0); i<m; i++)
	{
		k = idx[i];
		p = find(st[k]);
		q = find(ed[k]);
		//if (j > 0 && p != q)
		if (p != q && (j>0 || w[k]<0))
		{
			par[p] = q;
			--j;
			ans += w[k];
		}
		/*else if (w[k] < 0)
		{
			ans += w[k];
		}*/
	}
	printf("%d\n", (j>0?-1:ans));
	return 0;
}
