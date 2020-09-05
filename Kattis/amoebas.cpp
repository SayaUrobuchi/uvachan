#include <iostream>
using namespace std;

int ucnt, n, m;
int qx[1048576], qy[1048576];
int used[1024][1024];
string str[1024];

int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};

void bfs(int sx, int sy)
{
	int i, j, k, nx, ny;
	qx[0] = sx;
	qy[0] = sy;
	used[sx][sy] = ucnt;
	for (i=0, j=1; i<j; i++)
	{
		for (k=0; k<8; k++)
		{
			nx = qx[i] + dx[k];
			ny = qy[i] + dy[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && str[nx][ny] == '#' && used[nx][ny] != ucnt)
			{
				used[nx][ny] = ucnt;
				qx[j] = nx;
				qy[j] = ny;
				j++;
			}
		}
	}
}

int main()
{
	int i, j, ans;
	while (cin >> n >> m)
	{
		for (i=0; i<n; i++)
		{
			cin >> str[i];
		}
		++ucnt;
		for (i=0, ans=0; i<n; i++)
		{
			for (j=0; j<m; j++)
			{
				if (str[i][j] == '#' && used[i][j] != ucnt)
				{
					++ans;
					bfs(i, j);
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
