#include <iostream>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int ucnt, cnt;
int used[4][4], ary[4][4];
bool inner;

void dfs(int x, int y, int same)
{
	int i, tx, ty;
	used[x][y] = ucnt;
	++cnt;
	for (i=0; i<4; i++)
	{
		tx = x + dx[i];
		ty = y + dy[i];
		if (tx >= 0 && tx < 4 && ty >= 0 && ty < 4)
		{
			if (used[tx][ty] != ucnt && ary[tx][ty] == same)
			{
				dfs(tx, ty, same);
			}
		}
		else
		{
			inner = false;
		}
	}
}

int main()
{
	int i, j, k, t, msk, ans;
	bool gg;
	while (scanf("%d%d%d%d", &ary[0][0], &ary[0][1], &ary[0][2], &ary[0][3]) == 4)
	{
		for (i=1; i<4; i++)
		{
			for (j=0; j<4; j++)
			{
				scanf("%d", &ary[i][j]);
			}
		}
		for (i=0, msk=0; i<4; i++)
		{
			for (j=0; j<4; j++)
			{
				if (ary[i][j])
				{
					msk |= (1<<((i<<2)|j));
				}
			}
		}
		for (k=1, ans=0; k<65536; k++)
		{
			if ((k & msk) == msk)
			{
				for (i=0, t=0; i<4; i++)
				{
					for (j=0; j<4; j++)
					{
						ary[i][j] = ((k & (1 << ((i<<2) | j))) != 0);
						t += ary[i][j];
					}
				}
				++ucnt;
				for (i=0, gg=false; i<4&&!gg; i++)
				{
					for (j=0; j<4&&!gg; j++)
					{
						if (used[i][j] != ucnt)
						{
							inner = true;
							cnt = 0;
							dfs(i, j, ary[i][j]);
							if (ary[i][j])
							{
								if (cnt != t)
								{
									gg = true;
								}
							}
							else
							{
								if (inner)
								{
									gg = true;
								}
							}
						}
					}
				}
				ans += !gg;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

