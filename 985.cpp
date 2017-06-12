#include <stdio.h>
#include <string.h>

int n, m;
int hash[127];
int map[501][501][4];
int used[4][501][501];
int queuex[1000001], queuey[1000001];
int step[1000001];
int wayx[4] = {-1, 0, 1, 0};
int wayy[4] = {0, 1, 0, -1};
char str[1000];

int valid(int x, int y)
{
	return x > -1 && x < n && y > -1 && y < m;
}

int main()
{
	int i, j, k, s, x, y, tx, ty, temp;
	hash['N'] = 0;
	hash['E'] = 1;
	hash['S'] = 2;
	hash['W'] = 3;
	while(scanf("%d%d", &n, &m) == 2)
	{
		gets(str);
		memset(map, 0, sizeof(map));
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				if(i == n-1 && j == m-1)
				{
					break;
				}
				gets(str);
				for(k=0; str[k]; k++)
				{
					map[i][j][hash[str[k]]] = 1;
				}
			}
		}
		memset(used, 0, sizeof(used));
		queuex[0] = 0;
		queuey[0] = 0;
		step[0] = 0;
		for(i=0, j=1; i<j; i++)
		{
			x = queuex[i];
			y = queuey[i];
			s = step[i];
			for(k=0; k<4; k++)
			{
				if(map[x][y][k])
				{
					temp = s % 4;
					tx = x + wayx[(temp+k)%4];
					ty = y + wayy[(temp+k)%4];
					if(valid(tx, ty) && !used[temp][tx][ty])
					{
						if(tx == n-1 && ty == m-1)
						{
							break;
						}
						used[temp][tx][ty] = 1;
						queuex[j] = tx;
						queuey[j] = ty;
						step[j++] = s + 1;
					}
				}
			}
			if(k < 4)
			{
				break;
			}
		}
		if(i == j)
		{
			printf("no path to exit\n");
		}
		else
		{
			printf("%d\n", s+1);
		}
	}
	return 0;
}
