#include <stdio.h>
#include <string.h>

int map[1000][1000], dis[1000], dp[1000], n;

int main()
{
	int p, d, now, count, i, j, ctmp, ptmp, min;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &p, &d);
		for(i=0; i<p; i++)
		{
			for(j=0; j<p; j++)
			{
				map[i][j] = 0;
			}
		}
		while(d--)
		{
			scanf("%d%d", &i, &j);
			map[i][j] = 1;
			map[j][i] = 1;
		}
		memset(dis, 0, p * 4);
		dis[0] = -1;
		n = 0;
		for(i=1; i<p; i++)
		{
			dis[i] = map[0][i];
			if(dis[i]) now = i;
		}
		ptmp = p;
		while(--ptmp)
		{
			dp[now] = dis[now];
			dis[now] = -1;
			ctmp = dp[now] + 1;
			for(i=1, min=1023; i<p; i++)
			{
				if(map[now][i] && (!dis[i] || dis[i] > ctmp))
				{
					dis[i] = ctmp;
				}
				if(dis[i] > 0 && dis[i] < min)
				{
					min = dis[i];
					j = i;
				}
			}
			now = j;
		}
		for(i=1; i<p; i++)
		{
			printf("%d\n", dp[i]);
		}
		if(count) printf("\n");
	}
	return 0;
}
