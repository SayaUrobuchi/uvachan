#include <iostream>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int n, ucnt;
int used[128][128];
int m[128][128];

bool dfs(int x, int y, int z)
{
	int i, nx, ny;
	used[x][y] = ucnt;
	if (x == n-1 && y == n-1)
	{
		return true;
	}
	for (i=0; i<4; i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n)
		{
			if (used[nx][ny] != ucnt && m[nx][ny] <= z)
			{
				if (dfs(nx, ny, z))
				{
					return true;
				}
			}
		}
	}
	return false;
}

int main()
{
	int i, j, high, low, l, r, mid, ans;
	while (cin >> n)
	{
		for (i=0, high=-1, low=1e9; i<n; i++)
		{
			for (j=0; j<n; j++)
			{
				cin >> m[i][j];
				high = max(high, m[i][j]);
				low = min(low, m[i][j]);
			}
		}
		for (l=low, r=high; l<=r; )
		{
			mid = ((l+r) >> 1);
			++ucnt;
			if (dfs(0, 0, mid))
			{
				ans = mid;
				r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
