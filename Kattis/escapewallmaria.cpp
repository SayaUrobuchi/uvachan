#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
using pp = pair<int, int>;
using ppp = pair<int, pp>;

const int N = 105;
const int DX[] = {0, 1, 0, -1};
const int DY[] = {1, 0, -1, 0};
const int R = 1;
const int D = 2;
const int L = 4;
const int U = 8;

int can_move[128];
bool used[N][N];
char board[N][N];

int main()
{
	int n, m, o, i, j, k, sx, sy;
	can_move['0'] = (R | D | L | U);
	can_move['R'] = L;
	can_move['D'] = U;
	can_move['L'] = R;
	can_move['U'] = D;
	scanf("%d%d%d", &o, &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%s", board[i]);
		for (j=0; j<m; j++)
		{
			if (board[i][j] == 'S')
			{
				sx = i;
				sy = j;
			}
		}
	}
	vector<ppp> que;
	que.emplace_back(0, make_pair(sx, sy));
	used[sx][sy] = true;
	int ans = -1;
	for (i=0; i<que.size(); i++)
	{
		int d, x, y;
		forward_as_tuple(d, tie(x, y)) = que[i];
		if (x == 0 || y == 0 || x == n-1 || y == m-1)
		{
			ans = d;
			break;
		}
		for (k=0; k<4; k++)
		{
			int tx = x + DX[k];
			int ty = y + DY[k];
			if (tx >= 0 && tx < n && ty >= 0 && ty < m)
			{
				if (!used[tx][ty] && (can_move[board[tx][ty]] & (1 << k)))
				{
					que.emplace_back(d+1, make_pair(tx, ty));
					used[tx][ty] = true;
				}
			}
		}
	}
	if (ans == -1 || ans > o)
	{
		puts("NOT POSSIBLE");
	}
	else
	{
		printf("%d\n", ans);
	}
	return 0;
}
