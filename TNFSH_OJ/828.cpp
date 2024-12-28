#include <iostream>
using namespace std;

const int N = 1024;

char board[N][N];

int main()
{
	int n, m, c, x, y, i;
	scanf("%d%d%d", &n, &m, &c);
	scanf("%d%d", &x, &y);
	for (i=1; i<=n; i++)
	{
		scanf("%s", board[i]+1);
	}
	bool gg = (y == c);
	if (!gg)
	{
		int dir = 1;
		if (y > c)
		{
			dir = -1;
		}
		bool blocked = false;
		while (y != c && !blocked)
		{
			if (board[x][y] == 'X')
			{
				blocked = true;
			}
			x++;
			y += dir;
			if (x > n+1)
			{
				blocked = true;
			}
		}
		if (y == c || !blocked)
		{
			gg = true;
		}
	}
	puts(gg ? "noob" : "ezpz");
	return 0;
}