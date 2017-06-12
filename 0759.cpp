#include <stdio.h>
#include <string.h>

int ex[4000], ey[4000], ec[4000], dis[4000];

int main()
{
	int count, n, m, i, j, f;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		for(i=0; i<m; i++)
		{
			scanf("%d%d%d", &ex[i], &ey[i], &ec[i]);
		}
		for(i=0; i<=n; i++)
		{
			dis[i] = 80;
		}
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				if(dis[ex[j]] + ec[j] < dis[ey[j]])
				{
					dis[ey[j]] = dis[ex[j]] + ec[j];
				}
			}
		}
		for(j=0, f=0; j<m; j++)
		{
			if(dis[ex[j]] + ec[j] < dis[ey[j]])
			{
				dis[ey[j]] = dis[ex[j]] + ec[j];
				f = 1;
				break;
			}
		}
		if(f)
		{
			printf("1\n");
		}
		else
		{
			for(i=1; i<=n; i++)
			{
				if(dis[i] < 0)
				{
					break;
				}
			}
			if(i <= n)
			{
				printf("1\n");
			}
			else
			{
				printf("0\n");
			}
		}
	}
	return 0;
}
