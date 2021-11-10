#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
using p = pair<int, int>;
using pp = pair<p, p>;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
vector<pp> v[2];
char board[1024][1024];
int used[1024][1024][4];

int main()
{
	int n, m, i, k, x, y, s, d, sx, sy, ex, ey, nx, ny, ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
		--sx, --sy, --ex, --ey;
		for (i=0; i<n; i++)
		{
			scanf("%s", board[i]);
		}
		memset(used, 0x7f, sizeof(used));
		v[0].clear();
		v[1].clear();
		for (i=0; i<4; i++)
		{
			v[0].push_back({{0, i}, {sx, sy}});
			used[sx][sy][i] = 0;
		}
		for (i=0; ; )
		{
			if (v[i].empty())
			{
				i ^= 1;
			}
			pp now = v[i].back();
			v[i].pop_back();
			x = now.second.first;
			y = now.second.second;
			s = now.first.first;
			d = now.first.second;
			if (x == ex && y == ey)
			{
				ans = s;
				break;
			}
			nx = x + dx[d];
			ny = y + dy[d];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (board[nx][ny] != '#' && used[nx][ny][d] > s)
				{
					used[nx][ny][d] = s;
					v[i].push_back({{s, d}, {nx, ny}});
				}
			}
			for (k=0; k<4; k++)
			{
				if (used[x][y][k] > s+1)
				{
					used[x][y][k] = s+1;
					v[i^1].push_back({{s+1, k}, {x, y}});
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
