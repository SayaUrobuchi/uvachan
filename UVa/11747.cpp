#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define M 32768

int p[M], q[M], r[M], idx[M], par[M];

int comp(const void *pp, const void *qq)
{
	return r[*(int*)pp] - r[*(int*)qq];
}

int getpar(int t)
{
	if (par[t] < 0)
	{
		return t;
	}
	return par[t] = getpar(par[t]);
}

int main()
{
	int n, m, i, a, b, res;
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (!n && !m)
		{
			break;
		}
		for (i=0; i<m; i++)
		{
			scanf("%d%d%d", &p[i], &q[i], &r[i]);
			idx[i] = i;
		}
		qsort(idx, m, sizeof(idx[0]), comp);
		memset(par, -1, sizeof(par));
		res = 0;
		for (i=0; i<m; i++)
		{
			a = getpar(p[idx[i]]);
			b = getpar(q[idx[i]]);
			if (a != b)
			{
				par[a] = b;
			}
			else
			{
				printf(res?" %d":"%d", r[idx[i]]);
				++res;
			}
		}
		if (!res)
		{
			printf("forest");
		}
		printf("\n");
	}
	return 0;
}
