#include <stdio.h>
#include <string.h>

int cnum, res;
int used[10][10], du[10];
int xd[] = {1, 1, 2, 2, -1, -1, -2, -2};
int yd[] = {2, -2, 1, -1, 2, -2, 1, -1};
int clistx[10], clisty[10];
int qx[100], qy[100], step[100];
int dis[10][10], tbl[10][10];
char map[10][10];

int valid(int x, int y)
{
	return x >= 0 && x < 8 && y >= 0 && y < 8 && used[x][y] == 0 && map[x][y] != 'K' && map[x][y] != 'p';
}

void bfs(int ind)
{
	int x, y, s, tx, ty, i, j, k;
	memset(used, 0, sizeof(used));
	x=clistx[ind];
	y=clisty[ind];
	used[x][y] = 1;
	qx[0] = x;
	qy[0] = y;
	step[0] = 0;
	for(i=0, j=1; i<j; i++)
	{
		x = qx[i];
		y = qy[i];
		s = step[i] + 1;
		for(k=0; k<8; k++)
		{
			tx = x + xd[k];
			ty = y + yd[k];
			if(valid(tx, ty))
			{
				if(map[tx][ty] == 'P')
				{
					dis[ind][tbl[tx][ty]] = s;
				}
				used[tx][ty] = 1;
				qx[j] = tx;
				qy[j] = ty;
				step[j] = s;
				j++;
			}
		}
	}
}

int dfs(int ind, int d, int r)
{
	int i;
	if(r >= res)
	{
		return 0;
	}
	if(d >= cnum)
	{
		if(r < res)
		{
			res = r;
		}
		return 0;
	}
	for(i=0; i<cnum; i++)
	{
		if(du[i] == 0)
		{
			du[i] = 1;
			dfs(i, d+1, r+dis[ind][i]);
			du[i] = 0;
		}
	}
	return 0;
}

int main()
{
	int count, n, i, j, x, y;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0, cnum=0; i<8; i++)
		{
			scanf("%s", map[i]);
			for(j=0; j<8; j++)
			{
				if(map[i][j] == 'P')
				{
					clistx[cnum] = i;
					clisty[cnum] = j;
					tbl[i][j] = cnum;
					cnum++;
				}
				else if(map[i][j] == 'k')
				{
					x = i;
					y = j;
				}
			}
		}
		clistx[cnum] = x;
		clisty[cnum] = y;
		for(i=0; i<=cnum; i++)
		{
			bfs(i);
		}
		res = n+1;
		memset(du, 0, sizeof(du));
		dfs(cnum, 0, 0);
		printf(res==n+1?"No\n":"Yes\n");
	}
	return 0;
}
