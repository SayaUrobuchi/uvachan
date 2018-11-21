#include <stdio.h>
#include <string.h>

#define INFINITY 1000000000

int conn[101][101];
int cost[101][101];
int label[101];
int used[101];
int dist[101];
int from[101];

int main()
{
	int n, m, i, j, k, temp, maxdist, need, capacity;
	long long ans;
	while(scanf("%d%d", &n, &m) == 2)
	{
		memset(conn, 0, sizeof(conn));
		/*if(n > 100) while(1);*/
		while(m--)
		{
			scanf("%d%d%d", &i, &j, &k);
			conn[i][j] = conn[j][i] = 1;
			cost[i][j] = cost[j][i] = k;
			/*if(i > n || j > n) while(1);
			if(k > 100000000) while(1);*/
		}
		scanf("%d%d", &need, &capacity);
		/*if(capacity > 2147483647 || need > 2147483647) while(1);*/
		memset(label, 0, sizeof(label));
		for(ans=0; need; )
		{
			dist[1] = used[1] = 0;
			for(i=2; i<=n; i++)
			{
				dist[i] = INFINITY;
				used[i] = 0;
			}
			for(; ; )
			{
				for(i=1, maxdist=INFINITY; i<=n; i++)
				{
					if(!used[i] && dist[i] < maxdist)
					{
						maxdist = dist[i];
						temp = i;
					}
				}
				if(maxdist == INFINITY)
				{
					break;
				}
				used[temp] = 1;
				for(i=1; i<=n; i++)
				{
					if(!used[i] && conn[temp][i])
					{
						if(conn[i][temp])
						{
							if(dist[temp] + label[temp] - label[i] + cost[temp][i] < dist[i])
							{
								dist[i] = dist[temp] + label[temp] - label[i] + cost[temp][i];
								from[i] = temp;
							}
						}
						else
						{
							if(dist[temp] + label[temp] - label[i] - cost[temp][i] < dist[i])
							{
								dist[i] = dist[temp] + label[temp] - label[i] - cost[temp][i];
								from[i] = temp;
							}
						}
					}
				}
			}
			if(!used[n])
			{
				break;
			}
			for(i=n, k=0; i!=1; i=from[i])
			{
				j = from[i];
				if(conn[i][j])
				{
					k += cost[i][j];
					conn[j][i] = 0;
					conn[i][j] = 1;
				}
				else
				{
					k -= cost[i][j];
					conn[i][j] = conn[j][i] = 1;
				}
			}
			for(i=1; i<=n; i++)
			{
				if(label[i] < INFINITY)
				{
					label[i] += dist[i];
				}
			}
			if(need >= capacity)
			{
				ans += (long long)k * capacity;
				need -= capacity;
			}
			else
			{
				ans += (long long)k * need;
				need = 0;
			}
		}
		if(need)
		{
			printf("Impossible.\n");
		}
		else
		{
			printf("%lld\n", ans);
		}
	}
	return 0;
}
