#include <stdio.h>
#include <string.h>

int vis[10][10], tbl[2], used[60000], dp[60000], decx[60000], decy[60000], time[11];
int listx[12], listy[12], n, m, c;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
char map[10][10];

int valid(int x, int y, int z)
{
	return x >= 0 && x < n && y >= 0 && y < n && vis[x][y] == 0 && map[x][y] == z;
}

void visit(int x, int y, int z)
{
	int i, tx, ty;
	vis[x][y] = 1;
	c++;
	for(i=0; i<4; i++)
	{
		tx = x + dx[i];
		ty = y + dy[i];
		if(valid(tx, ty, z))
		{
			visit(tx, ty, z);
		}
	}
}

int getsc()
{
	int i, j;
	memset(vis, 0, sizeof(vis));
	tbl[0] = tbl[1] = 0;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			if(vis[i][j] == 0)
			{
				c = 0;
				visit(i, j, map[i][j]);
				if(c > tbl[map[i][j]-48])
				{
					tbl[map[i][j]-48] = c;
				}
			}
		}
	}
	return tbl[0]-tbl[1];
}

int play0(int, int, int, int);

int play1(int s, int mx, int depth, int ust)
{
	int i, sc, hs;
	if(used[ust])
	{
		return dp[ust];
	}
	used[ust] = 1;
	if(s == ((1<<m)-1))
	{
		return dp[ust]=getsc();
	}
	hs = 2147483647;
	for(i=0; i<m; i++)
	{
		if((s & (1<<i)) == 0)
		{
			map[listx[i]][listy[i]] = '1';
			sc = play0(s+(1<<i), hs, depth+1, ust+(time[i]<<1));
			if(sc < hs)
			{
				hs = sc;
				decx[ust] = listx[i];
				decy[ust] = listy[i];
			}
		}
	}
	return dp[ust]=hs;
}

int play0(int s, int mx, int depth, int ust)
{
	int i, sc, hs;
	if(used[ust])
	{
		return dp[ust];
	}
	used[ust] = 1;
	if(s == ((1<<m)-1))
	{
		return dp[ust]=getsc();
	}
	hs = -2147483647;
	for(i=0; i<m; i++)
	{
		if((s & (1<<i)) == 0)
		{
			map[listx[i]][listy[i]] = '0';
			sc = play1(s+(1<<i), hs, depth+1, ust+time[i]);
			if(sc > hs)
			{
				hs = sc;
				decx[ust] = listx[i];
				decy[ust] = listy[i];
			}
		}
	}
	return dp[ust]=hs;
}

int main()
{
	int i, j;
	time[0] = 1;
	for(i=1; i<11; i++)
	{
		time[i] = time[i-1] * 3;
	}
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		for(i=0, m=0; i<n; i++)
		{
			scanf("%s", map[i]);
			for(j=0; j<n; j++)
			{
				if(map[i][j] == '.')
				{
					listx[m] = i;
					listy[m++] = j;
				}
			}
		}
		memset(used, 0, sizeof(used));
		if(n % 2 == m % 2)
		{
			play0(0, 2147483647, 0, 0);
			printf("(%d,%d) %d\n", decx[0], decy[0], dp[0]);
		}
		else
		{
			play1(0, -2147483647, 0, 0);
			printf("(%d,%d) %d\n", decx[0], decy[0], -dp[0]);
		}
	}
	return 0;
}
