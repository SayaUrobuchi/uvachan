#include <stdio.h>
#include <string.h>

#define N 2048

int cc, dd;
int pn[N], con[N][N];
int dfn[N], low[N];
int sn, stk[N], in[N];

void dfs(int t)
{
	int i, nxt;
	dfn[t] = low[t] = ++dd;
	in[t] = 1;
	stk[sn++] = t;
	for (i=0; i<pn[t]&&cc<2; i++)
	{
		nxt = con[t][i];
		if (!dfn[nxt])
		{
			dfs(nxt);
			if (low[nxt] < low[t])
			{
				low[t] = low[nxt];
			}
		}
		else if (in[nxt])
		{
			if (dfn[nxt] < low[t])
			{
				low[t] = dfn[nxt];
			}
		}
	}
	if (dfn[t] == low[t])
	{
		cc++;
		while (sn--)
		{
			nxt = stk[sn];
			in[nxt] = 0;
			if (nxt == t)
			{
				break;
			}
		}
	}
}

int main()
{
	int n, m, p, q, r, i;
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (!n && !m)
		{
			break;
		}
		memset(pn, 0, sizeof(pn));
		for (i=0; i<m; i++)
		{
			scanf("%d%d%d", &p, &q, &r);
			con[p][pn[p]++] = q;
			if (r == 2)
			{
				con[q][pn[q]++] = p;
			}
		}
		memset(dfn, 0, sizeof(dfn));
		cc = 0;
		dd = 0;
		sn = 0;
		for (i=1; i<=n&&cc<2; i++)
		{
			if (!dfn[i])
			{
				dfs(i);
			}
		}
		printf("%d\n", cc<2 ? 1 : 0);
	}
	return 0;
}
