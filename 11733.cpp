#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int par[10005], p[100005], q[100005], r[100005], idx[100005];

int comp(const void *p, const void *q)
{
	return r[*(int*)p]>r[*(int*)q] ? 1 : -1;
}

int getpar(int t)
{
	if (par[t] < 0)
	{
		return t;
	}
	return par[t]=getpar(par[t]);
}

int main()
{
	int cas, count, n, m, o, i, c, res, pp, qq;
	cas = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d%d", &n, &m, &o);
		for (i=0; i<m; i++)
		{
			scanf("%d%d%d", &p[i], &q[i], &r[i]);
			idx[i] = i;
		}
		memset(par, -1, sizeof(par));
		qsort(idx, m, sizeof(int), comp);
		res = 0;
		c = n;
		for (i=0; i<m&&r[idx[i]]<o; i++)
		{
			pp = getpar(p[idx[i]]);
			qq = getpar(q[idx[i]]);
			if (pp != qq)
			{
				par[pp] = qq;
				res += r[idx[i]];
				c--;
			}
		}
		printf("Case #%d: %d %d\n", ++cas, res+c*o, c);
	}
	return 0;
}
