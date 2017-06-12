#include <stdio.h>
#include <string.h>

int n, m, ans;
int wayx[4] = {-1, 0, 1, 0};
int wayy[4] = {0, -1, 0, 1};
int map[64][64];
int chk[64][64];
char buf[4][500];

int ab(int now)
{
	if(now < 0)
	{
		return now + 4;
	}
	if(now > 3)
	{
		return now - 4;
	}
	return now;
}

void dfs(int x, int y, int dir)
{
	int d1, d2;
	if((x == n && y == m-1) || (x == n-1 && y == m))
	{
		ans++;
		return;
	}
	if(x < 0 || x >= n || y < 0 || y >= m)
	{
		return;
	}
	if(!map[x][y] || chk[x][y])
	{
		return;
	}
	chk[x][y] = 1;
	if(map[x][y] == 1)
	{
		dfs(x+wayx[dir], y+wayy[dir], dir);
	}
	else
	{
		d1 = ab(dir-1);
		d2 = ab(dir+1);
		dfs(x+wayx[d1], y+wayy[d1], d1);
		dfs(x+wayx[d2], y+wayy[d2], d2);
	}
	chk[x][y] = 0;
}

int main()
{
	int count, i, j, k;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		gets(buf[0]);
		gets(buf[0]);
		memset(map, 0, sizeof(map));
		memset(chk, 0, sizeof(chk));
		for(i=0; i<n; i++)
		{
			gets(buf[0]);
			gets(buf[1]);
			gets(buf[2]);
			gets(buf[3]);
			for(j=0, k=2; j<m; j++, k+=4)
			{
				if(buf[1][k] == '*')
				{
					if((buf[1][k-1] == '*' && buf[1][k-1] == buf[1][k+1]) || (buf[1][k] == '*' && buf[0][k] == buf[2][k]))
					{
						map[i][j] = 1;
					}
					else
					{
						map[i][j] = 2;
					}
				}
			}
		}
		ans = 0;
		dfs(0, 0, 2);
		dfs(0, 0, 3);
		printf("Number of solutions: %d\n", ans);
	}
	return 0;
}
