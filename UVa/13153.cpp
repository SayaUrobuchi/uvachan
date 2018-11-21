#include <stdio.h>
#include <string.h>

int tbl[1048576];
int rev[1048576];
int par[1048576];
int used[1048576], ut[1048576];
int ary[128];

int find(int p)
{
	if (par[p] < 0)
	{
		return p;
	}
	return par[p] = find(par[p]);
}

int main()
{
	int i, j, k, n, count, cas, cc, ans, uc, u, p, q, t;
	tbl[2] = 0;
	cc = 1;
	for (i=3; i<1024; i+=2)
	{
		if (!tbl[i])
		{
			for (j=i*i, k=i+i; j<1048576; j+=k)
			{
				tbl[j] = i;
			}
			rev[i] = cc++;
		}
	}
	for (; i<1048576; i+=2)
	{
		if (!tbl[i])
		{
			rev[i] = cc++;
		}
	}
	scanf("%d", &count);
	cas = 0;
	while (count--)
	{
		++cas;
		scanf("%d", &n);
		memset(par, -1, sizeof(par));
		uc = 0;
		ans = 0;
		for (i=0; i<n; i++)
		{
			scanf("%d", &k);
			if (k == 1)
			{
				++ans;
				continue;
			}
			u = -1;
			for (j=0; k>1; j++)
			{
				if (!(k & 1))
				{
					t = 2;
				}
				else if (tbl[k] == 0)
				{
					t = k;
				}
				else
				{
					t = tbl[k];
				}
				ary[j] = rev[t];
				if (used[rev[t]] == cas)
				{
					u = rev[t];
				}
				else
				{
					used[rev[t]] = cas;
					ut[uc++] = rev[t];
				}
				k /= t;
			}
			if (u < 0)
			{
				u = ary[0];
			}
			p = find(u);
			for (k=0; k<j; k++)
			{
				q = find(ary[k]);
				if (p != q)
				{
					par[q] = p;
				}
			}
		}
		for (i=0; i<uc; i++)
		{
			if (par[ut[i]] < 0)
			{
				++ans;
			}
		}
		printf("Case %d: %d\n", cas, ans);
	}
	return 0;
}
