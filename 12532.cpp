#include <stdio.h>
#include <string.h>

#define M 400000

char s[1024], ans[1048576];
int segp[M], segn[M], pp, nn;
int val[100005];

void add(int p, int q, int idx, int i, int v, int d)
{
	int c = ((p+q)>>1);
	if (v > 0)
	{
		segp[idx] += d;
	}
	else if (v < 0)
	{
		segn[idx] += d;
	}
	if (p != q)
	{
		if (i <= c)
		{
			add(p, c, idx<<1, i, v, d);
		}
		else
		{
			add(c+1, q, (idx<<1)+1, i, v, d);
		}
	}
}

void query(int p, int q, int idx, int i, int j)
{
	int c;
	if (i <= p && j >= q)
	{
		pp += segp[idx];
		nn += segn[idx];
		return;
	}
	c = ((p+q)>>1);
	if (j >= p && c >= i)
	{
		query(p, c, idx<<1, i, j);
	}
	if (j >= c+1 && q >= i)
	{
		query(c+1, q, (idx<<1)+1, i, j);
	}
}

int main()
{
	int n, m, i, j;
	char *ap;
	while (scanf("%d%d", &n, &m) == 2)
	{
		memset(segp, 0, sizeof(segp));
		memset(segn, 0, sizeof(segn));
		ap = ans;
		for (i=0; i<n; i++)
		{
			scanf("%d", &val[i]);
			if (val[i])
			{
				add(0, n-1, 1, i, val[i], 1);
			}
		}
		while (m--)
		{
			scanf("%s", s);
			if (*s == 'C')
			{
				scanf("%d%d", &i, &j);
				--i;
				if ((!val[i] && !j)
					|| (val[i] * j > 0))
				{
					continue;
				}
				if (val[i])
				{
					add(0, n-1, 1, i, val[i], -1);
				}
				val[i] = j;
				if (j)
				{
					add(0, n-1, 1, i, val[i], 1);
				}
			}
			else
			{
				scanf("%d%d", &i, &j);
				pp = 0;
				nn = 0;
				query(0, n-1, 1, i-1, j-1);
				if (pp+nn != (j-i+1))
				{
					*(ap++) = '0';
				}
				else if (nn & 1)
				{
					*(ap++) = '-';
				}
				else
				{
					*(ap++) = '+';
				}
			}
		}
		*ap = 0;
		puts(ans);
	}
	return 0;
}
