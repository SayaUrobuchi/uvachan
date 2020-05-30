#include <stdio.h>
#include <string.h>
#include <algorithm>

int dx[] = {0, 1};
int dy[] = {1, 0};

char buf0[1048576], buf1[1048576];
char board[32][32];

int main()
{
	int n, m, i, j, k, tx, ty, u;
	char *s, *t;
	s = buf0;
	t = buf1;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%s", board[i]);
		}
		for (i=0, s[0]=0; i<n; i++)
		{
			for (j=0; j<m; j++)
			{
				for (k=0; k<2; k++)
				{
					tx = i - dx[k];
					ty = j - dy[k];
					if (tx < 0 || ty < 0 || board[tx][ty] == '#')
					{
						for (tx=i, ty=j, u=0; tx<n&&ty<m&&board[tx][ty]!='#'; tx+=dx[k], ty+=dy[k], u++)
						{
							t[u] = board[tx][ty];
						}
						t[u] = 0;
						if (u > 1 && (!*s || strcmp(t, s) < 0))
						{
							std::swap(t, s);
						}
					}
				}
			}
		}
		puts(s);
	}
	return 0;
}
