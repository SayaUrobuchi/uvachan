#include <iostream>
#include <cstring>
using namespace std;

int dp[305][305][305];

int main()
{
	int n, i, j, k, a, b, t, u;
	memset(dp[0], 11, sizeof(dp[0]));
	while (scanf("%d%d%d", &n, &a, &b) == 3)
	{
		dp[0][0][0] = 0;
		for (i=1; i<=n; i++)
		{
			scanf("%d%d", &t, &u);
			for (j=0; j<=a+t; j++)
			{
				for (k=0; k<=b+u; k++)
				{
					if (j <= a && k <= b)
					{
						dp[i][min(j, a)][min(k, b)] = dp[i-1][min(j, a)][min(k, b)];
					}
					if (j-t >= 0 && k-u >= 0)
					{
						dp[i][min(j, a)][min(k, b)] = min(dp[i][min(j, a)][min(k, b)], dp[i-1][min(j-t, a)][min(k-u, b)]+1);
					}
				}
			}
		}
		printf("%d\n", dp[n][a][b]>n?-1:dp[n][a][b]);
	}
	return 0;
}

