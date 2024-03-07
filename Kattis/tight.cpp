#include <iostream>
#include <cmath>
using namespace std;

const int N = 105;
const int M = 12;

double dp[N][M];

int main()
{
	int n, m, i, j;
	while (scanf("%d%d", &m, &n) == 2)
	{
		for (i=0; i<=m; i++)
		{
			dp[1][i] = 1;
		}
		for (i=2; i<=n; i++)
		{
			for (j=0; j<=m; j++)
			{
				dp[i][j] = dp[i-1][j];
				if (j > 0)
				{
					dp[i][j] += dp[i-1][j-1];
				}
				if (j+1 <= m)
				{
					dp[i][j] += dp[i-1][j+1];
				}
			}
		}
		double son = 0;
		for (i=0; i<=m; i++)
		{
			son += dp[n][i];
		}
		double mom = pow(m+1, n);
		printf("%.10lf\n", son * 100 / mom);
	}
	return 0;
}
