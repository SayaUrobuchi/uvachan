#include <stdio.h>
#include <string.h>

#define INFINITY 1000000000

int map[105][105];
int conn[105][105];
int queue[6000], qdist[6000];
int dist[105], from[105];

int ab(int now)
{
	if(now < 0)
	{
		return -now;
	}
	return now;
}

int main()
{
	int n, m, i, j, k, d, flag, mindist, temp, now;
	long long ans, capacity, need;
	while(scanf("%d%d", &n, &m) == 2)
	{
		memset(conn, 0, sizeof(conn));
		while(m--)
		{
			scanf("%d%d%d", &i, &j, &k);
			map[i][j] = map[j][i] = k;
			conn[i][j] = conn[j][i] = 1;
		}
		scanf("%lld%lld", &need, &capacity);
		ans = 0;
		while(need)
		{
			dist[1] = 0;
			for(i=2; i<=n; i++)
			{
				dist[i] = INFINITY;
			}
			queue[0] = 1;
			qdist[0] = 0;
			for(i=0, j=1; i<j; i++)
			{
				now = queue[i];
				d = qdist[i];
				if(d == dist[now])
				{
					for(k=1; k<=n; k++)
					{
						if(conn[now][k] && d + map[now][k] < dist[k])
						{
							dist[k] = d + map[now][k];
							queue[j] = k;
							qdist[j++] = dist[k];
							from[k] = now;
						}
					}
				}
			}
			if(dist[n] == INFINITY)
			{
				break;
			}
			if(need >= capacity)
			{
				need -= capacity;
				ans += capacity * dist[n];
			}
			else
			{
				ans += need * dist[n];
				need = 0;
			}
			for(i=n; i!=1; i=from[i])
			{
				conn[from[i]][i] = 0;
				conn[i][from[i]] = 1;
				map[i][from[i]] = -ab(map[i][from[i]]);
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
