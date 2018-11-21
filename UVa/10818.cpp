#include <stdio.h>
#include <string.h>

#define INF 2147483647

int n, m, l;
int wayx[4] = {0, -1, 1, 0};
int wayy[4] = {1, 0, 0, -1};
int px[12], py[12];
int mark[25][25];
int sdis[12], dis[12][12];
int queuex[450], queuey[450], step[450], from[450], type[450];
int used[25][25];
int dused[10][1024], dp[10][1024];
char sstr[12][205], str[12][12][205], dstr[10][1024][205];
char map[25][25];
char buf[2008];
char ch[5] = {"ENSW"};
char *ptr;

int valid(int x, int y)
{
	return !used[x][y] && map[x][y] != '#' && map[x][y] != 'X';
}

char trans(char now)
{
	if(now == 'E')
	{
		return 'W';
	}
	if(now == 'N')
	{
		return 'S';
	}
	if(now == 'S')
	{
		return 'N';
	}
	return 'E';
}

char *rev(char *s)
{
	int i, l;
	l = strlen(s);
	for(i=0; i<l; i++)
	{
		buf[l-i-1] = trans(s[i]);
	}
	buf[i] = 0;
	return buf;
}

void getpath(int now)
{
	if(now == 0)
	{
		return;
	}
	getpath(from[now]);
	*(ptr++) = ch[type[now]];
}

int recursion(int tail, int num, int state)
{
	int i;
	if(dused[tail][state])
	{
		return dp[tail][state];
	}
	dused[tail][state] = 1;
	if(num == 1)
	{
		strcpy(dstr[tail][state], sstr[tail]);
		return dp[tail][state]=sdis[tail];
	}
	dp[tail][state] = INF;
	for(i=0; i<l; i++)
	{
		if(i != tail && (state & (1<<i)))
		{
			if(recursion(i, num-1, state-(1<<tail)) + dis[i][tail] < dp[tail][state])
			{
				dp[tail][state] = recursion(i, num-1, state-(1<<tail)) + dis[i][tail];
				sprintf(dstr[tail][state], "%s%s\0", dstr[i][state-(1<<tail)], str[i][tail]);
			}
			else if(recursion(i, num-1, state-(1<<tail)) + dis[i][tail] == dp[tail][state])
			{
				sprintf(buf, "%s%s\0", dstr[i][state-(1<<tail)], str[i][tail]);
				if(strcmp(buf, dstr[tail][state]) < 0)
				{
					strcpy(dstr[tail][state], buf);
				}
			}
		}
	}
	return dp[tail][state];
}

int main()
{
	int i, j, k, p, q, s, x, y, sx, sy, tx, ty, min, temp;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(!n && !m)
		{
			break;
		}
		gets(map[0]);
		for(i=0; i<n; i++)
		{
			gets(map[i]);
			for(j=0; j<m; j++)
			{
				if(map[i][j] == 'S')
				{
					sx = i;
					sy = j;
					map[i][j] = ' ';
				}
			}
		}
		queuex[0] = sx;
		queuey[0] = sy;
		step[0] = 0;
		memset(used, 0, sizeof(used));
		used[sx][sy] = 1;
		for(i=0, j=1, l=0; i<j; i++)
		{
			x = queuex[i];
			y = queuey[i];
			s = step[i];
			for(k=0; k<4; k++)
			{
				tx = x + wayx[k];
				ty = y + wayy[k];
				if(valid(tx, ty))
				{
					used[tx][ty] = 1;
					queuex[j] = tx;
					queuey[j] = ty;
					step[j] = s + 1;
					from[j] = i;
					type[j] = k;
					j++;
					if(map[tx][ty] == '*')
					{
						mark[tx][ty] = l;
						/*printf("%d %d: %d\n", tx, ty, l);*/
						px[l] = tx;
						py[l] = ty;
						sdis[l] = s + 1;
						ptr = sstr[l];
						getpath(j-1);
						l++;
						*ptr = 0;
					}
				}
			}
		}
		if(l == 0)
		{
			printf("Stay home!\n");
		}
		else
		{
			for(i=0; i<l; i++)
			{
				queuex[0] = px[i];
				queuey[0] = py[i];
				step[0] = 0;
				memset(used, 0, sizeof(used));
				used[px[i]][py[i]] = 1;
				for(p=0, q=1; p<q; p++)
				{
					x = queuex[p];
					y = queuey[p];
					s = step[p];
					for(k=0; k<4; k++)
					{
						tx = x + wayx[k];
						ty = y + wayy[k];
						if(valid(tx, ty))
						{
							used[tx][ty] = 1;
							queuex[q] = tx;
							queuey[q] = ty;
							step[q] = s + 1;
							from[q] = p;
							type[q] = k;
							q++;
							if(map[tx][ty] == '*')
							{
								ptr = str[i][mark[tx][ty]];
								dis[i][mark[tx][ty]] = s + 1;
								getpath(q-1);
								*ptr = 0;
								/*printf("%d => %d: %s\n", i, mark[tx][ty], str[i][mark[tx][ty]]);*/
							}
						}
					}
				}
			}
			memset(dused, 0, sizeof(dused));
			for(i=0, min=INF; i<l; i++)
			{
				recursion(i, l, (1<<l)-1);
				strcat(dstr[i][(1<<l)-1], rev(sstr[i]));
				if(sdis[i] + dp[i][(1<<l)-1] < min)
				{
					min = sdis[i] + dp[i][(1<<l)-1];
					temp = i;
				}
				else if(sdis[i] + dp[i][(1<<l)-1] == min)
				{
					if(strcmp(dstr[i][(1<<l)-1], dstr[temp][(1<<l)-1]) < 0)
					{
						temp = i;
					}
				}
			}
			printf("%s\n", dstr[temp][(1<<l)-1]);
		}
	}
	return 0;
}
