#include <iostream>

const int N = 16;
const int NN = 128;
const int M = 65536;

int dx[] = {2, -2, 1, -1, 1, -1};
int dy[] = {0, 0, 1, 1, -1, -1};

int qx[M], qy[M], qs[M];
int dp[N][NN][NN], used[N][NN][NN];

int main()
{
	int count, n, i, j, k, x, y, s, nx, ny, ns;
	qx[0] = 32;
	qy[0] = 32;
	qs[0] = 0;
	dp[0][32][32] = 1;
	for (i=0, j=1; i<j; i++)
	{
		x = qx[i];
		y = qy[i];
		s = qs[i];
		if (s+1 <= 14)
		{
			for (k=0; k<6; k++)
			{
				nx = x + dx[k];
				ny = y + dy[k];
				ns = s + 1;
				if (!used[ns][nx][ny])
				{
					used[ns][nx][ny] = true;
					qx[j] = nx;
					qy[j] = ny;
					qs[j] = ns;
					++j;
				}
				dp[ns][nx][ny] += dp[s][x][y];
			}
		}
	}
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		printf("%d\n", dp[n][32][32]);
	}
	return 0;
}
