#include <stdio.h>
#include <stdlib.h>

int lim;
int ary[5][5];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int stk[1024];

int t(char *s)
{
	if (*s == '*')
	{
		return -1;
	}
	return atoi(s)-1;
}

int calc(int x, int y, int n)
{
	if (n < 0)
	{
		return 0;
	}
	int p = x-(n>>2);
	int q = y-(n&3);
	if (p < 0)
	{
		p = -p;
	}
	if (q < 0)
	{
		q = -q;
	}
	return p+q;
}

int idfs(int x, int y, int d, int s)
{
	int i, tx, ty, ts, t;
	if (s == 0)
	{
		return 1;
	}
	if (lim - d < s)
	{
		return 0;
	}
	for (i=0; i<4; i++)
	{
		tx = x+dx[i];
		ty = y+dy[i];
		if (tx >= 0 && tx < 4 && ty >= 0 && ty < 4)
		{
			ts = s - calc(tx, ty, ary[tx][ty]);
			ts += calc(x, y, ary[tx][ty]);
			stk[d] = ary[tx][ty];
			t = ary[tx][ty];
			ary[x][y] = ary[tx][ty];
			if (idfs(tx, ty, d+1, ts))
			{
				return 1;
			}
			ary[tx][ty] = t;
		}
	}
	return 0;
}

int main()
{
	char s[16];
	int i, j, p, q, dis;
	while(scanf("%s", s) == 1)
	{
		ary[0][0] = t(s);
		p = 0;
		q = 0;
		dis = calc(0, 0, ary[0][0]);
		for (i=0; i<4; i++)
		{
			for (j=0; j<4; j++)
			{
				if (i+j)
				{
					scanf("%s", s);
					ary[i][j] = t(s);
					if (ary[i][j] < 0)
					{
						p = i;
						q = j;
					}
					dis += calc(i, j, ary[i][j]);
				}
			}
		}
		//printf("%d\n", dis);
		lim = dis;
		for (; ; lim += 2)
		{
			if (idfs(p, q, 0, dis))
			{
				break;
			}
		}
		for (i=0; i<lim; i++)
		{
			printf("%d\n", stk[i]+1);
		}
	}
	return 0;
}