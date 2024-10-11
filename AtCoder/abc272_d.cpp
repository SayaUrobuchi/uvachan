#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
using pp = pair<int, int>;
using ppp = pair<int, pp>;

const int N = 405;

bool used[N][N];
int dis[N][N];

int main()
{
	int n, m, i, j, k;
	scanf("%d%d", &n, &m);
	vector<pp> mov;
	for (i=0; i*i*2<=m; i++)
	{
		int t = m - i*i;
		int l = i, r = 1005;
		int ans = -1;
		while (l <= r)
		{
			int mid = ((l + r) >> 1);
			if (mid * mid == t)
			{
				ans = mid;
				break;
			}
			else if (mid * mid < t)
			{
				l = mid + 1;
			}
			else
			{
				r = mid - 1;
			}
		}
		if (ans >= 0)
		{
			for (l=-1; l<=1; l+=2)
			{
				for (r=-1; r<=1; r+=2)
				{
					mov.emplace_back(i*l, ans*r);
					mov.emplace_back(ans*l, i*r);
				}
			}
		}
	}
	vector<ppp> que;
	que.emplace_back(0, make_pair(1, 1));
	dis[1][1] = 0;
	used[1][1] = true;
	for (i=0; i<que.size(); i++)
	{
		int d, x, y;
		forward_as_tuple(d, tie(x, y)) = que[i];
		dis[x][y] = d;
		for (k=0; k<mov.size(); k++)
		{
			int tx = x + mov[k].first;
			int ty = y + mov[k].second;
			if (tx >= 1 && tx <= n && ty >= 1 && ty <= n)
			{
				if (!used[tx][ty])
				{
					used[tx][ty] = true;
					que.emplace_back(d+1, make_pair(tx, ty));
				}
			}
		}
	}
	const char *cl = " \n";
	for (i=1; i<=n; i++)
	{
		for (j=1; j<=n; j++)
		{
			int res = -1;
			if (used[i][j])
			{
				res = dis[i][j];
			}
			printf("%d%c", res, cl[j==n]);
		}
	}
	return 0;
}
