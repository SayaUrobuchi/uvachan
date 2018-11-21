#include <stdio.h>
#include <string.h>

int queuex[10000], queuey[10000], step[10000], map[100][100], n, m;
int wayx[4] = {0, 0, 1, -1};
int wayy[4] = {1, -1, 0, 0};
char chk[100][100];

int valid(int x, int y)
{
	return x > -1 && x < n && y > -1 && y < m;
}

int ab(int now)
{
	if(now < 0)
	{
		return -now;
	}
	return now;
}

int main()
{
	int count, i, j, k, x, y, s, tx, ty;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		memset(chk, 1, sizeof(chk));
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		if(i == j && i == 1)
		{
			printf("0\n");
			continue;
		}
		queuex[0] = queuey[0] = 0;
		step[0] = 0;
		chk[0][0] = 0;
		for(i=0, j=1; i<j; i++)
		{
			x = queuex[i];
			y = queuey[i];
			s = step[i] + 1;
			for(k=0; k<4; k++)
			{
				tx = x + wayx[k];
				ty = y + wayy[k];
				if(valid(tx, ty) && ab(map[x][y]-map[tx][ty]) < 6 && chk[tx][ty])
				{
					if(tx == n-1 && ty == m-1)
					{
						break;
					}
					chk[tx][ty] = 0;
					queuex[j] = tx;
					queuey[j] = ty;
					step[j++] = s;
				}
			}
			if(k < 4)
			{
				break;
			}
		}
		printf("%d\n", s);
	}
	return 0;
}
