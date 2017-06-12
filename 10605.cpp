#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ans;
int dis[11];
int aryx[11], aryy[11];
int conn[11][11];
int next[12];
int index[11];
int queuex[200], queuey[200];
int step[200];
int chk[11][11];
int wayx[4] = {0, 1, 0, -1};
int wayy[4] = {1, 0, -1, 0};
char map[11][12];

int comp(const void *p, const void *q)
{
	return dis[*(int*)p] - dis[*(int*)q];
}

int ab(int now)
{
	if(now < 0)
	{
		return -now;
	}
	return now;
}

int min(int p, int q)
{
	if(p < q)
	{
		return p;
	}
	return q;
}

int getdist(int p, int q)
{
	return ab(aryx[p]-aryx[q]) + ab(aryy[p]-aryy[q]);
}

void start(int);

void dfs(int now, int value)
{
	int i, j, temp;
	if(value > ans)
	{
		return;
	}
	/*printf("value %d\n", value);*/
	start(value);
	for(i=0; j=next[i]; i=j)
	{
		temp = index[j-1];
		if(dis[temp] > conn[now][temp])
		{
			next[i] = next[j];
			dfs(temp, value+conn[now][temp]);
			next[i] = j;
		}
	}
}

void start(int value)
{
	int now;
	now = next[0];
	if(!now)
	{
		ans = min(ans, value);
	}
	else
	{
		next[0] = next[now];
		dfs(index[now-1], value+dis[index[now-1]]);
		next[0] = now;
	}
}

int main()
{
	int count, n, m, i, j, p, q, o, x, y, s, tx, ty;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		for(i=0, o=0; i<n; i++)
		{
			scanf("%s", map[i]);
			for(j=0; j<m; j++)
			{
				if(map[i][j] == '*')
				{
					aryx[o] = i;
					aryy[o++] = j;
				}
			}
		}
		for(i=0; i<o; i++)
		{
			next[i] = i + 1;
			index[i] = i;
			queuex[0] = aryx[i];
			queuey[0] = aryy[i];
			step[0] = 0;
			memset(chk, 0, sizeof(chk));
			chk[aryx[i]][aryy[i]] = 1;
			for(p=0, q=1; p<q; p++)
			{
				x = queuex[p];
				y = queuey[p];
				s = step[p] + 1;
				for(j=0; j<4; j++)
				{
					tx = x + wayx[j];
					ty = y + wayy[j];
					if(map[tx][ty] == '#')
					{
						break;
					}
					if(!chk[tx][ty])
					{
						chk[tx][ty] = 1;
						queuex[q] = tx;
						queuey[q] = ty;
						step[q++] = s;
					}
				}
				if(j < 4)
				{
					break;
				}
			}
			dis[i] = s;
		}
		next[i] = 0;
		memset(conn, 0, sizeof(conn));
		qsort(index, o, sizeof(int), comp);
		for(i=1; i<o; i++)
		{
			for(j=0; j<i; j++)
			{
				conn[i][j] = conn[j][i] = getdist(i, j);
			}
		}
		ans = 2147483647;
		start(0);
		printf("%d\n", ans);
	}
	return 0;
}
