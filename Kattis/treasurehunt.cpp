#include <iostream>

const int OUT = 0;
const int LOST = 1;
const int FOUND = 2;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
const char *key = "NESW";
const char *reason[] = {"Out", "Lost"};

int ucnt;
int used[256][256];
int dir[128];
char board[256][256];

int main()
{
	int n, m, i, x, y, d, res, ans;
	for (i=0; key[i]; i++)
	{
		dir[key[i]] = i;
	}
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%s", board[i]);
		}
		++ucnt;
		for (x=0, y=0, ans=0; ; ans++)
		{
			if (x < 0 || x >= n || y < 0 || y >= m)
			{
				res = OUT;
				break;
			}
			else if (used[x][y] == ucnt)
			{
				res = LOST;
				break;
			}
			else if (board[x][y] == 'T')
			{
				res = FOUND;
				break;
			}
			d = dir[board[x][y]];
			used[x][y] = ucnt;
			x += dx[d];
			y += dy[d];
		}
		if (res == FOUND)
		{
			printf("%d\n", ans);
		}
		else
		{
			puts(reason[res]);
		}
	}
	return 0;
}
