#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define M 80000
#define N 512

int n;
int st[M], ed[M], dd[M], idx[M], par[N];
char nam[N][11], s0[11], s1[11];

int scomp(const void *p, const void *q)
{
	return strcmp((char*)p, (char*)q);
}

int ecomp(const void *p, const void *q)
{
	return dd[*(int*)p] > dd[*(int*)q] ? 1 : -1;
}

int find(char *s)
{
	int l, r, c, res;
	l = 0;
	r = n-1;
	while (l <= r)
	{
		c = ((l+r)>>1);
		res = strcmp(nam[c], s);
		if (!res)
		{
			return c;
		}
		else if (res > 0)
		{
			r = c-1;
		}
		else
		{
			l = c+1;
		}
	}
	return -1;
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
	int m, i, p, q, d, cc, ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (!n && !m)
		{
			break;
		}
		for (i=0; i<n; i++)
		{
			scanf("%s", nam[i]);
		}
		qsort(nam, n, sizeof(nam[0]), scomp);
		for (i=0; i<m; i++)
		{
			scanf("%s%s%d", s0, s1, &d);
			st[i] = find(s0);
			ed[i] = find(s1);
			dd[i] = d;
			idx[i] = i;
		}
		scanf("%*s");
		qsort(idx, m, sizeof(idx[0]), ecomp);
		memset(par, -1, sizeof(par));
		cc = 1;
		ans = 0;
		for (i=0; i<m; i++)
		{
			p = getpar(st[idx[i]]);
			q = getpar(ed[idx[i]]);
			if (p != q)
			{
				++cc;
				ans += dd[idx[i]];
				par[p] = q;
			}
		}
		if (cc != n)
		{
			puts("Impossible");
		}
		else
		{
			printf("%d\n", ans);
		}
	}
	return 0;
}
