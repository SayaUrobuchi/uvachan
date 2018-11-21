#include <stdio.h>
#include <string.h>

int map[105][105];
int conn[105][105];
int visited[105], used[105];
int dist[105], from[105];

int main()
{
	int n, m, i, j, k, flag, mindist, temp;
	long ans, capacity, need;
	while(scanf("%d%d", &n, &m) == 2)
	{
		memset(conn, 0, sizeof(conn));
		while(m--)
		{
			scanf("%d%d%d", &i, &j, &k);
			map[i][j] = map[j][i] = k;
			conn[i][j] = conn[j][i] = 1;
		}
		scanf("%d%d", &need, &capacity);
		ans = 0;
		while(need)
		{
			visited[1] = used[1] = 1;
			for(i=2; i<=n; i++)
			{
				if(conn[1][i])
				{
					dist[i] = map[1][i];
					from[i] = 1;
					used[i] = 1;
				}
				else
				{
					used[i] = 0;
				}
				visited[i] = 0;
			}
			flag = 1;
			while(flag)
			{
				flag = 0;
				for(i=2, mindist=2147483647; i<=n; i++)
				{
					if(!visited[i] && used[i])
					{
						if(dist[i] < mindist)
						{
							mindist = dist[i];
							temp = i;
							flag = 1;
						}
					}
				}
				if(flag)
				{
					if(temp == n)
					{
						break;
					}
					for(i=2; i<=n; i++)
					{
						if(conn[temp][i])
						{
							if(dist[i] > dist[temp] + map[temp][i] || !used[i])
							{
								dist[i] = dist[temp] + map[temp][i];
								from[i] = temp;
								used[i] = 1;
							}
						}
					}
					visited[temp] = 1;
				}
			}
			if(!flag)
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
				conn[i][from[i]]++;
				conn[from[i]][i]--;
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
