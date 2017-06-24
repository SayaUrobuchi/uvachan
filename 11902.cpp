#include <stdio.h>

int cnt;
int used[128], unable[128], conn[128];
int pp[128][128], pn[128];
char buf[512], negs[512];

void dfs(int now)
{
	int i, nxt;
	if (unable[now])
	{
		return;
	}
	used[now] = cnt;
	for (i=0; i<pn[now]; i++)
	{
		nxt = pp[now][i];
		if (!unable[nxt] && used[nxt] != cnt)
		{
			dfs(nxt);
		}
	}
}

int main()
{
	int cas, count, n, m, i, j, res;
	cas = 0;
	for (i=0; i<511; i++)
	{
		negs[i] = '-';
	}
	negs[i] = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=0; i<n; i++)
		{
			pn[i] = 0;
			for (j=0; j<n; j++)
			{
				scanf("%d", &m);
				if (m)
				{
					pp[i][pn[i]++] = j;
				}
			}
		}
		++cnt;
		dfs(0);
		for (i=0; i<n; i++)
		{
			conn[i] = (used[i] == cnt);
		}
		printf("Case %d:\n", ++cas);
		sprintf(buf, "+%.*s+", n+n-1, negs);
		puts(buf);
		for (i=0; i<n; i++)
		{
			++cnt;
			unable[i] = 1;
			dfs(0);
			unable[i] = 0;
			for (j=0; j<n; j++)
			{
				res = (conn[j] && used[j] != cnt);
				printf(res?"|Y":"|N");
			}
			puts("|");
			puts(buf);
		}
	}
	return 0;
}
