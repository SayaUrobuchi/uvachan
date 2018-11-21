#include <stdio.h>
#include <string.h>

int qx[1000000], qy[1000000], qs[1000000], qt[1000000];
int used[105][105][20];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int hash[128];
char map[105][105];

int is_key(int c)
{
	return hash[c] && c >= 97;
}

int is_door(int c)
{
	return hash[c] && c < 97;
}

int main()
{
	int n, m, i, j, k, x, y, s, t, sx, sy, nt, ns, kt, tx, ty;
	hash['b'] = hash['B'] = 1;
	hash['y'] = hash['Y'] = 2;
	hash['r'] = hash['R'] = 3;
	hash['g'] = hash['G'] = 4;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0 && m == 0)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%s", map[i]);
			for(j=0; j<m; j++)
			{
				if(map[i][j] == '*')
				{
					sx = i;
					sy = j;
					map[i][j] = '.';
				}
			}
		}
		qx[0] = sx;
		qy[0] = sy;
		qs[0] = 0;
		qt[0] = 0;
		memset(used, 0, sizeof(used));
		used[sx][sy][0] = 1;
		for(i=0, j=1; i<j; i++)
		{
			x = qx[i];
			y = qy[i];
			s = qs[i];
			t = qt[i];
			if(map[x][y] == 'X')
			{
				break;
			}
			for(k=0; k<4; k++)
			{
				tx = x + dx[k];
				ty = y + dy[k];
				ns = s + 1;
				nt = t;
				if(tx >= 0 && tx < n && ty >= 0 && ty < m && map[tx][ty] != '#')
				{
					if(is_key(map[tx][ty]))
					{
						kt = hash[map[tx][ty]]-1;
						nt |= (1<<kt);
					}
					else if(is_door(map[tx][ty]))
					{
						kt = hash[map[tx][ty]]-1;
						if(!(t & (1<<kt)))
						{
							continue;
						}
					}
					if(used[tx][ty][nt] == 0)
					{
						used[tx][ty][nt] = 1;
						qx[j] = tx;
						qy[j] = ty;
						qs[j] = ns;
						qt[j] = nt;
						j++;
					}
				}
			}
		}
		if(i == j)
		{
			printf("The poor student is trapped!\n");
		}
		else
		{
			printf("Escape possible in %d steps.\n", s);
		}
	}
	return 0;
}
