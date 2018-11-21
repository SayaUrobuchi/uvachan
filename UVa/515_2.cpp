#include <stdio.h>
#include <string.h>

int edgex[105], edgey[105], edgel[105];
int conn[105][105], map[105][105];
int dis[105];
char buf[1005];

int main()
{
	int n, m, i, j, k, p, q, l;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		memset(conn, 0, sizeof(conn));
		for(i=0; i<=n; i++)
		{
			map[i][i] = 0;
		}
		scanf("%d", &m);
		for(i=0, j=0; i<m; i++)
		{
			scanf("%d%d%s%d", &p, &q, buf, &l);
			if(!strcmp(buf, "gt"))
			{
				if(!conn[p+q][p-1] || -l-1 < map[p+q][p-1])
				{
					conn[p+q][p-1] = 1;
					map[p+q][p-1] = -l-1;
				}
			}
			else
			{
				if(!conn[p-1][p+q] || l-1 < map[p-1][p+q])
				{
					conn[p-1][p+q] = 1;
					map[p-1][p+q] = l-1;
				}
			}
		}
		for(k=0; k<=n; k++)
		{
			for(i=0; i<=n; i++)
			{
				if(conn[i][k])
				{
					for(j=0; j<=n; j++)
					{
						if(conn[k][j])
						{
							if(!conn[i][j] || map[i][k] + map[k][j] < map[i][j])
							{
								conn[i][j] = 1;
								map[i][j] = map[i][k] + map[k][j];
							}
						}
					}
				}
			}
		}
		for(i=0; i<=n; i++)
		{
			if(map[i][i] < 0)
			{
				break;
			}
		}
		if(i <= n)
		{
			printf("successful conspiracy\n");
		}
		else
		{
			printf("lamentable kingdom\n");
		}
	}
	return 0;
}
