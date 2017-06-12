#include <stdio.h>
#include <string.h>

char map[25][26], queue[625][2], way[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};

char walkable(int x, int y, int n, int m)
{
	if(x < 0 || x > n || y < 0 || y > m)
	{
		return 0;
	}
	if(map[x][y] == '1')
	{
		return 1;
	}
	return 0;
}

int main()
{
	int count, n, m, i, j, k, p, q, x, y, tmpx, tmpy, max;
	char buf[2];
	scanf("%d", &count);
	gets(buf);
	gets(buf);
	while(count--)
	{
		n = 0;
		while(gets(map[n]) && map[n][0])
		{
			n++;
		}
		m = strlen(map[0]);
		max = 0;
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				if(map[i][j] == '1')
				{
					map[i][j] = '0';
					queue[0][0] = i;
					queue[0][1] = j;
					for(p=0, q=1; p<q; p++)
					{
						x = queue[p][0];
						y = queue[p][1];
						for(k=0; k<8; k++)
						{
							if(walkable(tmpx=x+way[k][0], tmpy=y+way[k][1], n, m))
							{
								map[tmpx][tmpy] = '0';
								queue[q][0] = tmpx;
								queue[q++][1] = tmpy;
							}
						}
					}
					if(p > max)
					{
						max = p;
					}
				}
			}
		}
		printf("%d\n", max);
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
