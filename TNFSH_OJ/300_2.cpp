#include <stdio.h>
#include <string.h>

#define N 205
#define M 205

int cnt;
int dp[N][N], used[N][N];
int ary[N], nxt[N], tbl[M];

int eval(int p, int q)
{
	int i, t, ext;
	if (used[p][q] == cnt)
	{
		return dp[p][q];
	}
	used[p][q] = cnt;
	if (p == q)
	{
		return dp[p][q] = 1;
	}
	dp[p][q] = eval(p+1, q) + 1;
	for (i=nxt[p]; i!=-1&&i<=q; i=nxt[i])
	{
		t = eval(p+1, i-1) + eval(i, q);
		if (t < dp[p][q])
		{
			dp[p][q] = t;
		}
	}
	return dp[p][q];
}

int main()
{
	int count, i, j, n, m, t, last;
	scanf("%d", &count);
	while (count--)
	{
		++cnt;
		scanf("%d%d", &n, &m);
		for (i=0, j=0, last=0; i<n; i++)
		{
			scanf("%d", &t);
			if (t != last)
			{
				ary[j++] = t;
				last = t;
			}
		}
		n = j;
		memset(nxt, -1, sizeof(nxt));
		memset(tbl, -1, sizeof(tbl));
		for (i=0; i<n; i++)
		{
			if (tbl[ary[i]] != -1)
			{
				nxt[tbl[ary[i]]] = i;
			}
			tbl[ary[i]] = i;
		}
		printf("%d\n", eval(0, n-1));
	}
	return 0;
}
