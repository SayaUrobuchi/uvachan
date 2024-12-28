#include <iostream>
using namespace std;

const int N = 10;

char board[N][N+1];

int main()
{
	freopen("buckets.in", "r", stdin);
	freopen("buckets.out", "w", stdout);
	int i, j, bx, by, rx, ry, lx, ly;
	for (i=0; i<N; i++)
	{
		scanf("%s", board[i]);
		for (j=0; j<N; j++)
		{
			if (board[i][j] == 'B')
			{
				bx = i;
				by = j;
			}
			else if (board[i][j] == 'R')
			{
				rx = i;
				ry = j;
			}
			else if (board[i][j] == 'L')
			{
				lx = i;
				ly = j;
			}
		}
	}
	int ans = abs(bx-lx) + abs(by-ly) - 1;
	if (bx == lx && bx == rx && ry > min(by, ly) && ry < max(by, ly)
	 || by == ly && by == ry && rx > min(bx, lx) && rx < max(bx, lx))
	{
		ans += 2;
	}
	printf("%d\n", ans);
	return 0;
}
