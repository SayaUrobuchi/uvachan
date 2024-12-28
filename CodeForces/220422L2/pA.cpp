#include <iostream>
using namespace std;

long long dp[105][100005], from[105][100005];

int main()
{
	int n, m, i, j, k, w, v, t;
	string s;
	while (scanf("%d", &n) == 1)
	{
		for (i=1; i<=n; i++)
		{
			scanf("%d%d", &w, &v);
			for (j=0; j<=100000; j++)
			{
				dp[i][j] = dp[i-1][j];
				from[i][j] = j;
				if (j >= w && dp[i-1][j-w]+v > dp[i][j])
				{
					dp[i][j] = dp[i-1][j-w]+v;
					from[i][j] = j-w;
				}
			}
		}
		scanf("%d", &m);
		s.resize(n);
		for (i=0; i<m; i++)
		{
			scanf("%d", &t);
			for (j=t, k=n; k>=1; k--)
			{
				if (from[k][j] == j)
				{
					s[k-1] = '0';
				}
				else
				{
					s[k-1] = '1';
					j = from[k][j];
				}
			}
			puts(s.c_str());
		}
	}
	return 0;
}

