#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int M = 998244353;

int dp[512][512];
long long cc[512][512];
vector<int> v[512];

int calc(int l, int t, int u, int r)
{
	long long res = ((long long)dp[l][t-1]*dp[t+1][u-1]) % M;
	res = (res * dp[u+1][r]) % M;
	int a = (t-l)>>1;
	int b = (u-(t+1))>>1;
	int c = (r-u)>>1;
	res = (res * cc[a+b][a]) % M;
	res = (res * cc[a+b+c][c]) % M;
	return res;
}

int main()
{
	int n, m, n2, i, j, k, a, b, t, u, p;
	cc[0][0] = 1;
	for (i=1; i<512; i++)
	{
		cc[i][0] = 1;
		for (j=1; j<512; j++)
		{
			cc[i][j] = (cc[i-1][j-1] + cc[i-1][j]) % M;
		}
	}
	while (scanf("%d%d", &n, &m) == 2)
	{
		n2 = (n << 1);
		for (i=1; i<=n2; i++)
		{
			v[i].clear();
		}
		for (i=0; i<m; i++)
		{
			scanf("%d%d", &a, &b);
			if ((b-a) & 1)
			{
				v[a].emplace_back(b);
			}
		}
		for (i=0; i<=n2; i++)
		{
			dp[i+1][i] = 1;
			sort(v[i].begin(), v[i].end());
		}
		for (k=2; k<=n2; k+=2)
		{
			for (i=1, j=i+k-1; j<=n2; i++, j++)
			{
				dp[i][j] = 0;
				for (t=i; t<j; t+=2)
				{
					for (u=0; u<v[t].size()&&v[t][u]<=j; u++)
					{
						p = v[t][u];
						dp[i][j] = (dp[i][j] + calc(i, t, p, j)) % M;
					}
				}
			}
		}
		printf("%d\n", dp[1][n2]);
	}
	return 0;
}

