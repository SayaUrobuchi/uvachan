#include <stdio.h>
#include <string.h>

char map[200][200], sing[200][200];
int queue[40000][3], n, m;

char valid(int x, int y)
{
	return x > -1 && x < n && y > -1 && y < m;
}

char dangerous(int x, int y, int x1, int y1, int l)
{
	return valid(x1, y1) && sing[x1][y1] && (x-x1) * (x-x1) + (y-y1) * (y-y1) <= l * l;
}

char check(int x, int y)
{
	return valid(x, y) && map[x][y];
}

int main()
{
	int i, j, k, l, x, y, x1, y1, in;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(!n && !m)
		{
			break;
		}
		memset(map, 1, sizeof(map));
		scanf("%d", &in);
		while(in--)
		{
			scanf("%d%d", &x, &y);
			map[x-1][y-1] = 0;
		}
		scanf("%d", &in);
		while(in--)
		{
			scanf("%d%d%d", &x, &y, &l);
			x--;
			y--;
			memset(sing, 1, sizeof(sing));
			queue[0][0] = x;
			queue[0][1] = y;
			sing[x][y] = 0;
			map[x][y] = 0;
			for(i=0, j=1; i<j; i++)
			{
				x1 = queue[i][0];
				y1 = queue[i][1];
				if(dangerous(x, y, x1-1, y1, l))
				{
					queue[j][0] = x1-1;
					queue[j++][1] = y1;
					sing[x1-1][y1] = 0;
					map[x1-1][y1] = 0;
				}
				if(dangerous(x, y, x1+1, y1, l))
				{
					queue[j][0] = x1+1;
					queue[j++][1] = y1;
					sing[x1+1][y1] = 0;
					map[x1+1][y1] = 0;
				}
				if(dangerous(x, y, x1, y1-1, l))
				{
					queue[j][0] = x1;
					queue[j++][1] = y1-1;
					sing[x1][y1-1] = 0;
					map[x1][y1-1] = 0;
				}
				if(dangerous(x, y, x1, y1+1, l))
				{
					queue[j][0] = x1;
					queue[j++][1] = y1+1;
					sing[x1][y1+1] = 0;
					map[x1][y1+1] = 0;
				}
			}
		}
		if(map[0][0] && map[n-1][m-1])
		{
			if(n-1 || m-1)
			{
				map[0][0] = 0;
				queue[0][0] = 0;
				queue[0][1] = 0;
				queue[0][2] = 0;
				for(i=0, j=1; i<j; i++)
				{
					x = queue[i][0];
					y = queue[i][1];
					k = queue[i][2] + 1;
					if(check(x-1, y))
					{
						queue[j][0] = x-1;
						queue[j][1] = y;
						queue[j++][2] = k;
						map[x-1][y] = 0;
					}
					if(check(x+1, y))
					{
						if(x+1 == n-1 && y == m-1)
						{
							break;
						}
						queue[j][0] = x+1;
						queue[j][1] = y;
						queue[j++][2] = k;
						map[x+1][y] = 0;
					}
					if(check(x, y-1))
					{
						queue[j][0] = x;
						queue[j][1] = y-1;
						queue[j++][2] = k;
						map[x][y-1] = 0;
					}
					if(check(x, y+1))
					{
						if(x == n-1 && y+1 == m-1)
						{
							break;
						}
						queue[j][0] = x;
						queue[j][1] = y+1;
						queue[j++][2] = k;
						map[x][y+1] = 0;
					}
				}
				if(i == j)
				{
					printf("Impossible.\n");
				}
				else
				{
					printf("%d\n", k);
				}
			}
			else
			{
				printf("Impossible.\n");
			}
		}
		else
		{
			printf("Impossible.\n");
		}
	}
	return 0;
}
