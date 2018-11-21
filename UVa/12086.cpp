#include <stdio.h>
#include <string.h>

int ary[200005], seg[650005];
char s[16];

void add(int l, int r, int p, int loc, int val)
{
	int c;
	seg[p] += val;
	if (l < r)
	{
		c = ((l+r) >> 1);
		if (loc <= c)
		{
			add(l, c, p<<1, loc, val);
		}
		else
		{
			add(c+1, r, (p<<1)+1, loc, val);
		}
	}
}

int qes(int l, int r, int p, int st, int ed)
{
	int c, res;
	if (st <= l && ed >= r)
	{
		return seg[p];
	}
	c = ((l+r) >> 1);
	res = 0;
	if (st <= c && ed >= l)
	{
		res += qes(l, c, p<<1, st, ed);
	}
	if (st <= r && ed >= c+1)
	{
		res += qes(c+1, r, (p<<1)+1, st, ed);
	}
	return res;
}

int main()
{
	int cas, n, i, j;
	cas = 0;
	while (scanf("%d", &n) == 1)
	{
		if (!n)
		{
			break;
		}
		memset(seg, 0, sizeof(seg));
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			add(0, n-1, 1, i, ary[i]);
		}
		if (cas)
		{
			puts("");
		}
		printf("Case %d:\n", ++cas);
		while (scanf("%s", s) == 1)
		{
			if (*s == 'E')
			{
				break;
			}
			if (*s == 'S')
			{
				scanf("%d%d", &i, &j);
				--i;
				add(0, n-1, 1, i, j-ary[i]);
				ary[i] = j;
			}
			else
			{
				scanf("%d%d", &i, &j);
				printf("%d\n", qes(0, n-1, 1, i-1, j-1));
			}
		}
	}
	return 0;
}
