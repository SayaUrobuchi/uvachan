#include <stdio.h>
#include <string.h>

int n, m;
int used[15000];
int wayx[4] = {-1, 0, 1, 0};
int wayy[4] = {0, 1, 0, -1};
int queuex[15000], queuey[15000], step[15000], face[15000], color[15000];
char map[30][30];

int encode(int x, int y, int f, int c)
{
	return x + y*25 + f*625 + c*2500;
}

int valid(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}

int mod(int now, int div)
{
	if(now < 0)
	{
		return now + div;
	}
	if(now >= div)
	{
		return now - div;
	}
	return now;
}

int main()
{
	int cas, i, j, x, y, s, f, c, sx, sy, tx, ty, dx, dy, temp;
	cas = 0;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(!n && !m)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%s", map[i]);
			for(j=0; j<m; j++)
			{
				if(map[i][j] == 'S')
				{
					sx = i;
					sy = j;
				}
				else if(map[i][j] == 'T')
				{
					dx = i;
					dy = j;
				}
			}
		}
		memset(used, 0, sizeof(used));
		queuex[0] = sx;
		queuey[0] = sy;
		step[0] = 0;
		face[0] = 0;
		color[0] = 0;
		for(i=0, j=1; i<j; i++)
		{
			x = queuex[i];
			y = queuey[i];
			s = step[i] + 1;
			f = face[i];
			c = color[i];
			tx = x + wayx[f];
			ty = y + wayy[f];
			if(valid(tx, ty) && map[tx][ty] != '#')
			{
				if(!used[temp=encode(tx, ty, f, mod(c+1, 5))])
				{
					used[temp] = 1;
					if(tx == dx && ty == dy && c == 4)
					{
						break;
					}
					queuex[j] = tx;
					queuey[j] = ty;
					step[j] = s;
					face[j] = f;
					color[j] = mod(c+1, 5);
					j++;
				}
			}
			if(!used[temp=encode(x, y, mod(f+1, 4), c)])
			{
				used[temp] = 1;
				queuex[j] = x;
				queuey[j] = y;
				step[j] = s;
				face[j] = mod(f+1, 4);
				color[j] = c;
				j++;
			}
			if(!used[temp=encode(x, y, mod(f-1, 4), c)])
			{
				used[temp] = 1;
				queuex[j] = x;
				queuey[j] = y;
				step[j] = s;
				face[j] = mod(f-1, 4);
				color[j] = c;
				j++;
			}
		}
		if(cas)
		{
			printf("\n");
		}
		printf("Case #%d\n", ++cas);
		if(i == j)
		{
			printf("destination not reachable\n");
		}
		else
		{
			printf("minimum time = %d sec\n", s);
		}
	}
	return 0;
}
