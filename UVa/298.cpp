#include <stdio.h>
#include <string.h>

int n, m, x, y, spx, spy;
int map[30][30];
int queue[50000], step[50000], used[50000];

int encode(int a, int b, int c, int d)
{
	return a + b * 30 + (c+3) * 30 * 30 + (d+3) * 30 * 30 * 7;
}

void decode(int state)
{
	x = state % 30;
	state /= 30;
	y = state % 30;
	state /= 30;
	spx = state % 7 - 3;
	state /= 7;
	spy = state % 7 - 3;
}

int valid(int a, int b)
{
	return a >= 0 && a < n && b >= 0 && b < m && map[a][b] == 0;
}

int main()
{
	int count, i, j, k, l, o, s, x1, x2, y1, y2, sx, sy, ex, ey, tx, ty, tspx, tspy, state;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
		scanf("%d", &o);
		memset(map, 0, sizeof(map));
		while(o--)
		{
			scanf("%d%d%d%d", &x1, &x2, &y1, &y2);
			for(i=x1; i<=x2; i++)
			{
				for(j=y1; j<=y2; j++)
				{
					map[i][j] = 1;
				}
			}
		}
		if(sx == ex && sy == ey)
		{
			printf("Optimal solution takes 0 hops.\n");
		}
		else
		{
			queue[0] = encode(sx, sy, 0, 0);
			step[0] = 0;
			memset(used, 0, sizeof(used));
			used[queue[0]] = 1;
			for(i=0, j=1; i<j; i++)
			{
				decode(queue[i]);
				s = step[i] + 1;
				for(k=0; k<9; k++)
				{
					tspx = spx + (k/3-1);
					tspy = spy + (k%3-1);
					if(tspx >= -3 && tspx <= 3 && tspy >= -3 && tspy <= 3)
					{
						tx = x + tspx;
						ty = y + tspy;
						state = encode(tx, ty, tspx, tspy);
						if(valid(tx, ty) && !used[state])
						{
							if(tx == ex && ty == ey)
							{
								break;
							}
							used[state] = 1;
							queue[j] = state;
							step[j] = s;
							j++;
						}
					}
				}
				if(k < 8)
				{
					break;
				}
			}
			if(i < j)
			{
				printf("Optimal solution takes %d hops.\n", s);
			}
			else
			{
				printf("No solution.\n");
			}
		}
	}
	return 0;
}
