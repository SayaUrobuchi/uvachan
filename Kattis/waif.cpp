#include <iostream>
#include <cstring>

const int N = 128;
const int NO_MATCH = -1;

int ucnt;
int used[N];
int ary[N][N], cnt[N];
int bry[N][N], len[N];
int par[N], cat[N], lim[N];

bool match(int cur)
{
	int i, tar, c, j, nxt;
	for (i=0; i<cnt[cur]; i++)
	{
		tar = ary[cur][i];
		if (par[tar] == NO_MATCH && lim[cat[tar]] > 0)
		{
			--lim[cat[tar]];
			par[tar] = cur;
			return true;
		}
	}
	for (i=0; i<cnt[cur]; i++)
	{
		tar = ary[cur][i];
		if (used[tar] != ucnt)
		{
			used[tar] = ucnt;
			if (par[tar] != NO_MATCH)
			{
				if (match(par[tar]))
				{
					par[tar] = cur;
					return true;
				}
			}
			else
			{
				c = cat[tar];
				for (j=0; j<len[c]; j++)
				{
					nxt = bry[c][j];
					if (used[nxt] != ucnt && par[nxt] != NO_MATCH)
					{
						used[nxt] = ucnt;
						if (match(par[nxt]))
						{
							par[nxt] = NO_MATCH;
							par[tar] = cur;
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

int main()
{
	int n, m, o, i, j, ans;
	while (scanf("%d%d%d", &n, &m, &o) == 3)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &cnt[i]);
			for (j=0; j<cnt[i]; j++)
			{
				scanf("%d", &ary[i][j]);
			}
		}
		memset(par, NO_MATCH, sizeof(par));
		memset(cat, 0, sizeof(cat));
		lim[0] = 1e9;
		for (i=1; i<=o; i++)
		{
			scanf("%d", &len[i]);
			for (j=0; j<len[i]; j++)
			{
				scanf("%d", &bry[i][j]);
				cat[bry[i][j]] = i;
			}
			scanf("%d", &lim[i]);
		}
		for (i=0, ans=0; i<n; i++)
		{
			++ucnt;
			if (match(i))
			{
				++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
