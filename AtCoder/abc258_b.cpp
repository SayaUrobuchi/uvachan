#include <iostream>
using namespace std;

const int N = 16;
const int DX[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int DY[] = {1, 0, -1, 0, 1, -1, 1, -1};

int board[N][N];

int main()
{
	int n, i, j, k;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			scanf("%1d", &board[i][j]);
		}
	}
	long long ans = 0;
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			for (k=0; k<8; k++)
			{
				long long t = 0;
				int x = i;
				int y = j;
				int d;
				for (d=0; d<n; d++)
				{
					t = t * 10 + board[x][y];
					x = (x + DX[k] + n) % n;
					y = (y + DY[k] + n) % n;
				}
				ans = max(t, ans);
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}