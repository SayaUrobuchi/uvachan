#include <iostream>
using namespace std;

const int M = 1000000007;

int ary[128];
int dp[1048576];

int main()
{
	int n, m, i, j, t;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		dp[0] = 1;
		for (j=1; j<=m; j++)
		{
			dp[j] = 0;
			for (i=0; i<n; i++)
			{
				if (j >= ary[i])
				{
					dp[j] = (dp[j]+dp[j-ary[i]]) % M;
				}
			}
		}
		printf("%d\n", dp[m]);
	}
	return 0;
}

