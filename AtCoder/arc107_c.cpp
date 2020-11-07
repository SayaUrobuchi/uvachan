#include <iostream>

const int M = 998244353;

int n, m;
int ary[64][64];
int par[64], cnt[64];
long long tbl[64];

int getpar(int cur)
{
	if (cur == par[cur])
	{
		return cur;
	}
	return par[cur] = getpar(par[cur]);
}

bool row(int p, int q)
{
	int i;
	for (i=0; i<n; i++)
	{
		if (ary[p][i] + ary[q][i] > m)
		{
			return false;
		}
	}
	return true;
}

bool col(int p, int q)
{
	int i;
	for (i=0; i<n; i++)
	{
		if (ary[i][p] + ary[i][q] > m)
		{
			return false;
		}
	}
	return true;
}

bool (*check[2])(int, int) = {row, col};

int main()
{
	int i, j, k, p, q;
	long long ans, t;
	tbl[0] = 1;
	for (i=1; i<=50; i++)
	{
		tbl[i] = (tbl[i-1]*i) % M;
	}
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			for (j=0; j<n; j++)
			{
				scanf("%d", &ary[i][j]);
			}
		}
		for (k=0, ans=1; k<2; k++)
		{
			for (i=0; i<n; i++)
			{
				par[i] = i;
				cnt[i] = 1;
			}
			for (i=0; i<n; i++)
			{
				for (j=i+1; j<n; j++)
				{
					if (check[k](i, j))
					{
						p = getpar(i);
						q = getpar(j);
						if (p != q)
						{
							par[p] = q;
							cnt[q] += cnt[p];
						}
					}
				}
			}
			for (i=0, t=1; i<n; i++)
			{
				if (par[i] == i)
				{
					t = (t*tbl[cnt[i]]) % M;
				}
			}
			ans = (ans*t) % M;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
