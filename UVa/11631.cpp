#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int par[200005], pa[200005], pb[200005], pc[200005], idd[200005];

int comp(const void *p, const void *q)
{
	return pc[*(int*)p] > pc[*(int*)q] ? 1 : -1;
}

int getpar(int n)
{
	return ~par[n]?par[n]=getpar(par[n]):n;
}

int main()
{
	int n, m, i, p, q, res;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0 && m == 0)
		{
			break;
		}
		memset(par, -1, sizeof(par));
		for(i=0; i<m; i++)
		{
			scanf("%d%d%d", &pa[i], &pb[i], &pc[i]);
			idd[i] = i;
		}
		qsort(idd, m, sizeof(idd[0]), comp);
		for(i=0, res=0; i<m; i++)
		{
			p = getpar(pa[idd[i]]);
			q = getpar(pb[idd[i]]);
			if(p != q)
			{
				par[p] = q;
			}
			else
			{
				res += pc[idd[i]];
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
