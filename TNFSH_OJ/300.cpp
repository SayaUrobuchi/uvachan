#include <stdio.h>
#include <string.h>

#define N 205
#define M 205

int cnt;
int dp[N][N][M], used[N][N][M];
int ary[N], nxt[N], tbl[M];

int eval(int p, int q, int c)
{
	int i, t, ext;
	if (used[p][q][c] == cnt)
	{
		return dp[p][q][c];
	}
	used[p][q][c] = cnt;
	if (p > q)
	{
		return dp[p][q][c] = 0;
	}
	ext = (ary[p] == c ? 0 : 1);
	if (p == q)
	{
		return dp[p][q][c] = ext;
	}
	dp[p][q][c] = eval(p+1, q, c) + ext;
	for (i=nxt[p]; i!=-1&&i<=q; i=nxt[i])
	{
		t = eval(p+1, i-1, ary[p]) + eval(i+1, q, c) + ext;
		if (t < dp[p][q][c])
		{
			dp[p][q][c] = t;
		}
	}
	return dp[p][q][c];
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
		printf("%d\n", eval(0, n-1, 0));
	}
	return 0;
}
