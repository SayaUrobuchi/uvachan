#include <iostream>
#pragma GCC optimize("Ofast,no-stack-protector")
using namespace std;

const int N = 5055;
const int M = 1048576;

int ucnt;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int used[N][N];
int bqx[2][M], bqy[2][M];
int *qx, *qy, *nx, *ny;
char board[N][N];

int main()
{
	int n, m, i, j, k, l, cur, x, y, o, ans;
	ios::sync_with_stdio(0);
	cin.tie(0);
	qx = bqx[0];
	qy = bqy[0];
	nx = bqx[1];
	ny = bqy[1];
	while (cin >> n >> m)
	{
		for (i=0; i<n; i++)
		{
			cin >> board[i];
		}
		cin >> o;
		++ucnt;
		ans = 0;
		for (cur=0, l=0; cur<o; cur++)
		{
			for (i=0, j=0; i<l; i++)
			{
				for (k=0; k<4; k++)
				{
					x = qx[i] + dx[k];
					y = qy[i] + dy[k];
					if (x >= 0 && x < n && y >= 0 && y < m)
					{
						if (used[x][y] != ucnt && board[x][y] == '.')
						{
							used[x][y] = ucnt;
							nx[j] = x;
							ny[j] = y;
							j++;
						}
					}
				}
			}
			cin >> x >> y;
			--x;
			--y;
			if (used[x][y] != ucnt)
			{
				used[x][y] = ucnt;
				nx[j] = x;
				ny[j] = y;
				j++;
			}
			ans += j;
			cout << ans << "\n";
			l = j;
			swap(qx, nx);
			swap(qy, ny);
		}
	}
	return 0;
}
