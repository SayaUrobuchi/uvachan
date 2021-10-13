#include <iostream>
#include <vector>
using namespace std;

const int M = 1000000007;

int ary[1<<21];
int dp[22][(1<<21)];
vector<int> v[22];

int main()
{
	int n, i, j, k, l, t;
	while (scanf("%d", &n) == 1)
	{
		dp[0][0] = 1;
		for (i=1; i<=n; i++)
		{
			v[i].clear();
		}
		for (i=1; i<(1<<n); i++)
		{
			for (l=i, j=0; l; l-=(l&-l), j++);
			v[j].emplace_back(i);
		}
		for (i=1; i<=n; i++)
		{
			for (j=0; j<n; j++)
			{
				scanf("%d", &ary[1<<j]);
			}
			for (t=0; t<v[i].size(); t++)
			{
				j = v[i][t];
				dp[i][j] = 0;
				for (l=j; l; l-=k)
				{
					k = (l & -l);
					if (ary[k])
					{
						dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % M;
					}
				}
			}
		}
		printf("%d\n", dp[n][(1<<n)-1]);
	}
	return 0;
}
