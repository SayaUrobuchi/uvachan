#include <stdio.h>
#include <string.h>

int last[11];
int map[11][11], num[11];
int cost[11][11];
int dis[11];
int chk[11];

void backtracing(int now)
{
	if(last[now])
	{
		backtracing(last[now]);
	}
	printf(" %d", now);
}

int main()
{
	int cas, n, i, j, s, e, temp, tempi;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		for(i=1; i<=n; i++)
		{
			scanf("%d", &num[i]);
			for(j=0; j<num[i]; j++)
			{
				scanf("%d%d", &map[i][j], &cost[i][j]);
			}
		}
		scanf("%d%d", &s, &e);
		for(i=1; i<=n; i++)
		{
			dis[i] = 2147483647;
		}
		for(i=0; i<num[s]; i++)
		{
			dis[map[s][i]] = cost[s][i];
			last[map[s][i]] = s;
		}
		memset(chk, 0, sizeof(chk));
		chk[s] = 1;
		last[s] = 0;
		for(i=1; i<n; i++)
		{
			for(j=1, temp=2147483647; j<=n; j++)
			{
				if(!chk[j] && dis[j] < temp)
				{
					temp = dis[j];
					tempi = j;
				}
			}
			chk[tempi] = 1;
			if(tempi == e)
			{
				break;
			}
			for(j=0; j<num[tempi]; j++)
			{
				if(!chk[map[tempi][j]] && dis[tempi] + cost[tempi][j] < dis[map[tempi][j]])
				{
					dis[map[tempi][j]] = dis[tempi] + cost[tempi][j];
					last[map[tempi][j]] = tempi;
				}
			}
		}
		printf("Case %d: Path =", ++cas);
		backtracing(e);
		printf("; %d second delay\n", dis[e]);
	}
	return 0;
}
