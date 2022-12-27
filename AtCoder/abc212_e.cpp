#include <iostream>
#include <vector>
using namespace std;

const int M = 998244353;

int dp[5050][5050];
vector<int> v[5050];

int main()
{
	int n, m, o, i, j, k, a, b, t, u;
	while (scanf("%d%d%d", &n, &m, &o) == 3)
	{
		for (i=1; i<=n; i++)
		{
			v[i].clear();
			v[i].emplace_back(i);
			dp[0][i] = 0;
		}
		dp[0][1] = 1;
		t = 1;
		for (i=0; i<m; i++)
		{
			scanf("%d%d", &a, &b);
			v[a].emplace_back(b);
			v[b].emplace_back(a);
		}
		for (i=1; i<=o; i++)
		{
			for (u=0, j=1; j<=n; j++)
			{
				dp[i][j] = t;
				for (k=0; k<v[j].size(); k++)
				{
					dp[i][j] = (dp[i][j] + M - dp[i-1][v[j][k]]) % M;
				}
				u = (u + dp[i][j]) % M;
			}
			t = u;
		}
		printf("%d\n", dp[o][1]);
	}
	return 0;
}

