#include <stdio.h>
#include <string.h>

char map[20][21], map2[20][21], loc[12][2], path[12][12][401], chk[11], list[12];
char way[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}, ptemp[2], spath[5000];
int dis[12][12], queue[401][5], cost[12][2], ans;

char valid(int r, int c, int x, int y)
{
	return x > -1 && x < r && y > -1 && y < c;
}

char* getpath(int now)
{
	if(queue[now][2] == -1)
	{
		spath[0] = 0;
	}
	else
	{
		if(!queue[now][2])
		{
			strcat(getpath(queue[now][4]), "E");
		}
		else if(queue[now][2] == 1)
		{
            strcat(getpath(queue[now][4]), "S");
		}
		else if(queue[now][2] == 2)
		{
            strcat(getpath(queue[now][4]), "W");
		}
		else
		{
            strcat(getpath(queue[now][4]), "N");
		}
	}
	return spath;
}

void dfs(int now, int depth, int lim, int c, int weight)
{
	int i;
	if(depth == lim)
	{
		c += dis[now][lim] * weight;
		if(ans > c)
		{
			ans = c;
			spath[0] = 0;
			for(i=1; i<lim; i++)
			{
				strcat(spath, path[list[i-1]][list[i]]);
				strcat(spath, "P");
			}
			strcat(spath, path[list[i-1]][lim]);
		}
		return;
	}
	if(c >= ans)
	{
		return;
	}
	for(i=1; i<lim; i++)
	{
		if(chk[i])
		{
			chk[i] = 0;
			list[depth] = i;
			dfs(i, depth+1, lim, c+dis[now][i]*weight+cost[i][0], weight+cost[i][1]);
			chk[i] = 1;
		}
	}
}

int main()
{
	int cas, r, c, i, j, k, l, p, q, s, sx, sy, tx, ty, x, y, xtemp, ytemp;
	char buf[100], ch;
	cas = 0;
	while(scanf("%d%d", &r, &c) == 2)
	{
		if(!r && !c)
		{
			break;
		}
		gets(buf);
		for(i=0, k=1; i<r; i++)
		{
			gets(map[i]);
			for(j=0; j<c; j++)
			{
				ch = map[i][j];
				if(ch == 'S')
				{
					loc[0][0] = i;
					loc[0][1] = j;
					map[i][j] = 0;
				}
				else if(ch == 'T')
				{
					tx = i;
					ty = j;
				}
				else if(ch == '*')
				{
					loc[k][0] = i;
					loc[k][1] = j;
					map[i][j] = k++;
				}
			}
		}
		loc[k][0] = tx;
		loc[k][1] = ty;
		map[tx][ty] = k++;
		for(i=0; i<k; i++)
		{
			memcpy(map2[0], map[0], sizeof(map));
			map2[queue[0][0]=loc[i][0]][queue[0][1]=loc[i][1]] = '#';
			queue[0][2] = -1;
			queue[0][3] = 0;
			for(p=0, q=1, l=1; p<q; p++)
			{
				x = queue[p][0];
				y = queue[p][1];
				s = queue[p][3] + 1;
				for(j=0; j<4; j++)
				{
					xtemp = x + way[j][0];
					ytemp = y + way[j][1];
					if(valid(r, c, xtemp, ytemp) && map2[xtemp][ytemp] != '#')
					{
						queue[q][0] = xtemp;
						queue[q][1] = ytemp;
						queue[q][2] = j;
						queue[q][3] = s;
						queue[q++][4] = p;
						if(map2[xtemp][ytemp] != '.')
						{
							strcpy(path[i][map2[xtemp][ytemp]], getpath(q-1));
							dis[i][map2[xtemp][ytemp]] = s;
							if(l++ == k)
							{
								break;
							}
						}
						map2[xtemp][ytemp] = '#';
					}
				}
				if(j < 4)
				{
					break;
				}
			}
			if(l != k)
			{
				break;
			}
		}
		scanf("%d", &s);
		for(j=1; j<k-1; j++)
		{
			scanf("%d%d", &cost[j][0], &cost[j][1]);
		}
		if(i < k)
		{
			printf("Hunt #%d\nThe hunt is impossible.\n\n", ++cas);
		}
		else
		{
			list[0] = 0;
			memset(chk, 1, sizeof(chk));
			ans = 2147483647;
            dfs(0, 1, k-1, 0, s);
			printf("Hunt #%d\nMinimum energy required = %d cal\n%s\n\n", ++cas, ans, spath);
		}
	}
	return 0;
}
