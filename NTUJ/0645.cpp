#include <stdio.h>
#include <string.h>

int used[1005], dp[1005], pnum[1005], map[1005][1005], dis[1005], md[1005][1005];
int qq[1000005], dd[1000005];

int recurs(int tar)
{
	int i, sum, nex;
	if(used[tar])
	{
		return dp[tar];
	}
	used[tar] = 1;
	if(tar == 2)
	{
		return dp[tar]=1;
	}
	for(i=0, sum=0; i<pnum[tar]; i++)
	{
		nex = map[tar][i];
		if(dis[nex] < dis[tar])
		{
			sum += recurs(nex);
		}
	}
	return dp[tar]=sum;
}

int main()
{
	int n, m, i, j, k, p, q, r, now, tar;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0)
		{
			break;
		}
		memset(pnum, 0, sizeof(pnum));
		for(i=0; i<m; i++)
		{
			scanf("%d%d%d", &p, &q, &r);
			map[p][pnum[p]++] = q;
			map[q][pnum[q]++] = p;
			md[p][q] = md[q][p] = r;
		}
		for(i=1; i<=n; i++)
		{
			dis[i] = 1000000000;
		}
		dis[2] = 0;
		qq[0] = 2;
		dd[0] = 0;
		for(i=0, j=1; i<j; i++)
		{
			now = qq[i];
			if(dd[i] != dis[now])
			{
				continue;
			}
			for(k=0; k<pnum[now]; k++)
			{
				tar = map[now][k];
				if(dis[now] + md[now][tar] < dis[tar])
				{
					dis[tar] = dis[now] + md[now][tar];
					dd[j] = dis[tar];
					qq[j++] = tar;
				}
			}
		}
		memset(used, 0, sizeof(used));
		printf("%d\n", recurs(1));
	}
	return 0;
}
