#include <stdio.h>
#include <string.h>

int edgex[105], edgey[105], edgel[105];
int conn[105][105], map[105][105];
int dis[105];
char buf[1005];

int main()
{
	int n, m, i, j, p, q, l;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		memset(conn, 0, sizeof(conn));
		scanf("%d", &m);
		for(i=0, j=0; i<m; i++)
		{
			scanf("%d%d%s%d", &p, &q, buf, &l);
			if(!strcmp(buf, "gt"))
			{
				if(!conn[p+q][p-1])
				{
					conn[p+q][p-1] = 1;
					map[p+q][p-1] = -l-1;
				}
				else
				{
					if(-l-1 >= map[p+q][p-1])
					{
						continue;
					}
				}
				edgex[j] = p+q;
				edgey[j] = p-1;
				edgel[j++] = -l-1;
			}
			else
			{
				if(!conn[p-1][p+q])
				{
					conn[p-1][p+q] = 1;
					map[p-1][p+q] = l-1;
				}
				else
				{
					if(l-1 >= map[p-1][p+q])
					{
						continue;
					}
				}
				edgex[j] = p-1;
				edgey[j] = p+q;
				edgel[j++] = l-1;
			}
		}
		m = j;
		memset(dis, 1, sizeof(dis));
		dis[0] = 0;
		for(i=1; i<=n; i++)
		{
			for(j=0; j<m; j++)
			{
				if(dis[edgex[j]] + edgel[j] < dis[edgey[j]])
				{
					dis[edgey[j]] = dis[edgex[j]] + edgel[j];
				}
			}
		}
		for(j=0; j<m; j++)
		{
			if(dis[edgex[j]] + edgel[j] < dis[edgey[j]])
			{
				break;
			}
		}
		if(j < m)
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
