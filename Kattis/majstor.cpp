#include <iostream>
#include <cstring>

int cnt[64][128];
int tbl[128][128];
char s[1024], buf[1024];
const char *key = "SPR";

int main()
{
	int n, m, i, j, k, t, u, real, best;
	tbl['S']['S'] = tbl['P']['P'] = tbl['R']['R'] = 1;
	tbl['S']['P'] = tbl['P']['R'] = tbl['R']['S'] = 2;
	while (scanf("%d", &n) == 1)
	{
		scanf("%s%d", s, &m);
		memset(cnt, 0, sizeof(cnt));
		for (i=0; i<m; i++)
		{
			scanf("%s", buf);
			for (j=0; j<n; j++)
			{
				cnt[j][buf[j]]++;
			}
		}
		for (i=0, real=0, best=0; i<n; i++)
		{
			for (j=0; key[j]; j++)
			{
				real += cnt[i][key[j]] * tbl[s[i]][key[j]];
			}
			for (k=0, t=0; key[k]; k++)
			{
				for (j=0, u=0; key[j]; j++)
				{
					u += cnt[i][key[j]] * tbl[key[k]][key[j]];
				}
				if (u > t)
				{
					t = u;
				}
			}
			best += t;
		}
		printf("%d\n%d\n", real, best);
	}
	return 0;
}
