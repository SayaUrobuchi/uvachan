#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
using pp = pair<double, long long>;

int n;
long long dp[25][25];
double rat[4];
priority_queue<pp, vector<pp>, greater<pp> > pq;

void dfs(int depth, int total, double r, long long c)
{
	int i;
	if (depth == 3)
	{
		for (i=total; i<n; i++)
		{
			r *= rat[depth];
		}
		c *= dp[n][total];
		pq.emplace(r, c);
		return;
	}
	for (i=total; i<=n; i++)
	{
		long long nc = c * dp[i][total];
		dfs(depth+1, i, r, nc);
		r *= rat[depth];
	}
}

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i=0; i<4; i++)
	{
		scanf("%lf", &rat[i]);
	}
	dp[0][0] = 1;
	for (i=1; i<=n; i++)
	{
		dp[i][0] = 1;
		for (j=1; j<=n; j++)
		{
			dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
		}
	}
	dfs(0, 0, 1.0, 1LL);
	double ans = 0;
	while (!pq.empty())
	{
		double r;
		long long c;
		tie(r, c) = pq.top();
		pq.pop();
		if (c == 1 && pq.empty())
		{
			break;
		}
		if (c > 1)
		{
			ans += (r+r) * (c>>1);
			pq.emplace(r+r, c>>1);
		}
		if (c & 1)
		{
			double nr;
			long long nc;
			tie(nr, nc) = pq.top();
			pq.pop();
			ans += (r+nr);
			pq.emplace(r+nr, 1);
			if (nc > 1)
			{
				pq.emplace(nr, nc-1);
			}
		}
	}
	printf("%.6lf\n", ans);
	return 0;
}
