#include <stdio.h>
#include <string.h>

int n, m;
int tbl[4] = {'N', 'E', 'S', 'W'};
int queuex[160000], queuey[160000];
int boxx[160000], boxy[160000];
int dir[160000], push[160000], last[160000];
int chk[160000];
int wayx[4] = {-1, 0, 1, 0};
int wayy[4] = {0, 1, 0, -1};
char map[20][21];

int valid(int x, int y)
{
	return x > -1 && x < n && y > -1 && y < m && map[x][y] == '.';
}

int chkbox(int x, int y)
{
	int n, e, s, w;
	n = valid(x+wayx[0], y+wayy[0]);
	e = valid(x+wayx[1], y+wayy[1]);
	s = valid(x+wayx[2], y+wayy[2]);
	w = valid(x+wayx[3], y+wayy[3]);
	return !((!n && !e) || (!e && !s) || (!s && !w) || (!w && !n));
}

int trans(int i, int j, int k, int l)
{
	return i + j*20 + k*400 + l*8000;
}

void backtracing(int now)
{
	int temp;
	if(!now)
	{
		return;
	}
	backtracing(temp=last[now]);
	if(push[temp] != push[now])
	{
		printf("%c", tbl[dir[now]]);
	}
	else
	{
		printf("%c", tbl[dir[now]]+32);
	}
}

int main()
{
	int cas, i, j, k, x, y, p, sx, sy, ex, ey, tx, ty, bx, by, temp, ans, choice;
	cas = 0;
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
				if(map[i][j] == 'T')
				{
					map[i][j] = '.';
					ex = i;
					ey = j;
				}
				else if(map[i][j] == 'S')
				{
					map[i][j] = '.';
					sx = i;
					sy = j;
				}
				else if(map[i][j] == 'B')
				{
					map[i][j] = '.';
					bx = i;
					by = j;
				}
			}
		}
		printf("Maze #%d\n", ++cas);
		if(chkbox(bx, by))
		{
			memset(chk, 0, sizeof(chk));
			queuex[0] = sx;
			queuey[0] = sy;
			boxx[0] = bx;
			boxy[0] = by;
			push[0] = 0;
			chk[trans(sx, sy, bx, by)] = 1;
			last[0] = -1;
			for(i=0, j=1, ans=2147483647, choice=-1; i<j; i++)
			{
				x = queuex[i];
				y = queuey[i];
				bx = boxx[i];
				by = boxy[i];
				p = push[i];
				for(k=0; k<4; k++)
				{
					tx = x + wayx[k];
					ty = y + wayy[k];
					if(valid(tx, ty))
					{
						if(tx == bx && ty == by)
						{
							sx = bx + wayx[k];
							sy = by + wayy[k];
							if(valid(sx, sy))
							{
								temp = trans(tx, ty, sx, sy);
								if(!chk[temp] || chk[temp] > p + 2)
								{
									if(sx == ex && sy == ey)
									{
										if(p + 1 < ans)
										{
											ans = p + 1;
											choice = j;
											queuex[j] = -100;
											queuey[j] = -100;
											last[j] = i;
											dir[j] = k;
											push[j++] = p + 1;
										}
									}
									else if(chkbox(sx, ty))
									{
										chk[temp] = p + 2;
										queuex[j] = tx;
										queuey[j] = ty;
										boxx[j] = sx;
										boxy[j] = sy;
										last[j] = i;
										dir[j] = k;
										push[j++] = p + 1;
									}
								}
							}
						}
						else
						{
							temp = trans(tx, ty, bx, by);
							if(!chk[temp] || chk[temp] > p + 1)
							{
								chk[temp] = p + 1;
								queuex[j] = tx;
								queuey[j] = ty;
								boxx[j] = bx;
								boxy[j] = by;
								last[j] = i;
								dir[j] = k;
								push[j++] = p;
							}
						}
					}
				}
			}
			if(choice == -1)
			{
				printf("Impossible.\n\n");
			}
			else
			{
				backtracing(choice);
				printf("\n\n");
			}
		}
		else
		{
			printf("Impossible.\n\n");
		}
	}
	return 0;
}
