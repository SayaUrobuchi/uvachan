#include <stdio.h>
#include <string.h>

int ss, tt, m;
int used[1005][2], q[100005], st[100005], map[1005][1005];
int px[10005], py[10005], dis[1005][2], stt[100005];

int bfs()
{
	int i, j, k, nn, ns, nex, stat;
	memset(used, 0, sizeof(used));
	memset(dis, -1, sizeof(dis));
	q[0] = ss;
	st[0] = 0;
	stt[0] = 0;
	used[ss][0] = 1;
	used[ss][1] = 1;
	for(i=0, j=1; i<j; i++)
	{
		nn = q[i];
		ns = st[i] + 1;
		stat = stt[i];
		if(stat && stat != used[nn][1])
		{
			continue;
		}
		dis[nn][!!stat] = st[i];
		for(k=1; k<=m; k++)
		{
			if(map[nn][k])
			{
				if(stat == 0)
				{
					if(used[k][0] == 0)
					{
						used[k][0] = 1;
						q[j] = k;
						st[j] = ns;
						stt[j] = stat;
						j++;
					}
				}
				else
				{
					if(used[k][1] == 0 || (used[k][1] > stat && ns <= dis[k][1]))
					{
						used[k][1] = stat;
						q[j] = k;
						st[j] = ns;
						stt[j] = stat;
						dis[k][1] = ns;
						j++;
					}
				}
			}
			else
			{
				if(stat == 0 && map[k][nn])
				{
					if(used[k][1] == 0 || (used[k][1] > map[k][nn] && ns <= dis[k][1]))
					{
						used[k][1] = map[k][nn];
						q[j] = k;
						st[j] = ns;
						stt[j] = map[k][nn];
						dis[k][1] = ns;
						j++;
					}
				}
			}
		}
	}
	return 2147483647;
}

int main()
{
	int n, i, j, res, rd, temp;
	while(scanf("%d", &m) == 1)
	{
		if(m == 0)
		{
			break;
		}
		scanf("%d%d", &ss, &tt);
		scanf("%d", &n);
		memset(map, 0, sizeof(map));
		for(i=1; i<=n; i++)
		{
			scanf("%d%d", &px[i], &py[i]);
			if(map[px[i]][py[i]] == 0 || map[px[i]][py[i]] > i)
			{
				map[px[i]][py[i]] = i;
			}
		}
		if(ss == tt)
		{
			printf("0 0\n");
			continue;
		}
		bfs();
		if(dis[tt][1] == -1 || dis[tt][1] >= dis[tt][0])
		{
			printf("%d %d\n", dis[tt][0], 0);
		}
		else
		{
			printf("%d %d\n", dis[tt][1], used[tt][1]);
		}
	}
	return 0;
}
