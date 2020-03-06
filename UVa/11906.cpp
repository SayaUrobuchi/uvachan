#include <stdio.h>

const int N = 128;
const int QN = N*N;

int dx[] = {1, 1, -1, -1};
int dy[] = {1, -1, 1, -1};
int board[N][N];
int qx[QN], qy[QN], used[N][N], mk[N][N];
int ans[2];

int main()
{
	int count, n, m, p, q, r, cas, ucnt, x, y, tx, ty, i, j, k, c, uuu;
	cas = 0;
	ucnt = 0;
	uuu = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d%d%d%d", &n, &m, &p, &q, &r);
		ucnt++;
		while (r--)
		{
			scanf("%d%d", &x, &y);
			board[x][y] = ucnt;
		}
		qx[0] = 0;
		qy[0] = 0;
		used[0][0] = ucnt;
		ans[0] = ans[1] = 0;
		for (i=0, j=1; i<j; i++)
		{
			x = qx[i];
			y = qy[i];
			uuu++;
			for (k=0, c=0; k<8; k++)
			{
				if (k & 4)
				{
					tx = x + p * dx[k&3];
					ty = y + q * dy[k&3];
				}
				else
				{
					tx = x + q * dx[k&3];
					ty = y + p * dy[k&3];
				}
				if (tx >= 0 && tx < n && ty >= 0 && ty < m && board[tx][ty] != ucnt)
				{
					if (mk[tx][ty] != uuu)
					{
						c++;
						mk[tx][ty] = uuu;
					}
					if (used[tx][ty] != ucnt)
					{
						used[tx][ty] = ucnt;
						qx[j] = tx;
						qy[j] = ty;
						j++;
					}
				}
			}
			ans[c&1]++;
		}
		printf("Case %d: %d %d\n", ++cas, ans[0], ans[1]);
	}
	return 0;
}
