#include <stdio.h>

#define M 5000000
#define UNKNOWN 0
#define ESCAPED 1
#define LOOPED 2

int n, extend, cnt, idd;
int qs[M], ql[M], qq[M];
int dir[128], used[16][16], stat[16][16];
int sn, sx[128], sy[128];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
char map[16][16];
const char *ds[] = {"east", "south", "west", "north"};

void move(int *p, int *q)
{
	int i, tx, ty;
	for (i=0; i<idd; i++)
	{
		tx = *p + dx[dir[i]];
		ty = *q + dy[dir[i]];
		if (tx >= 0 && tx < n && ty >= 0 && ty < n && map[tx][ty] == 'O')
		{
			continue;
		}
		*p = tx;
		*q = ty;
		if (tx < 0 || ty >= n || ty < 0 || ty >= n)
		{
			return;
		}
	}
}

int check()
{
	int res, i, j, k, p, q, ans;
	++cnt;
	extend = 0;
	ans = 1;
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			if (map[i][j] == '.' && used[i][j] != cnt)
			{
				p = i;
				q = j;
				sn = 0;
				res = UNKNOWN;
				while (1)
				{
					if (p < 0 || p >= n || q < 0 || q >= n)
					{
						extend = 1;
						res = ESCAPED;
						break;
					}
					else if (used[p][q] == cnt)
					{
						if (stat[p][q] != ESCAPED)
						{
							res = LOOPED;
						}
						else
						{
							res = ESCAPED;
						}
						break;
					}
					used[p][q] = cnt;
					stat[p][q] = UNKNOWN;
					sx[sn] = p;
					sy[sn] = q;
					++sn;
					move(&p, &q);
				}
				if (p != i || q != j)
				{
					extend = 1;
				}
				for (k=0; k<sn; k++)
				{
					stat[sx[k]][sy[k]] = res;
				}
				if (res != ESCAPED)
				{
					ans = 0;
				}
			}
		}
	}
	return ans;
}

int idfs(int depth)
{
	int i;
	if (depth == idd)
	{
		if (check())
		{
			return 1;
		}
		return 0;
	}
	for (i=0; i<4; i++)
	{
		dir[depth] = i;
		if (idfs(depth+1))
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	int count, i, j, k;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=0; i<n; i++)
		{
			scanf("%s", map[i]);
		}
		for (idd=1; ; idd++)
		{
			if (idfs(0))
			{
				break;
			}
		}
		for (i=0; i<idd; i++)
		{
			puts(ds[dir[i]]);
		}
		if (count)
		{
			puts("");
		}
	}
	return 0;
}
