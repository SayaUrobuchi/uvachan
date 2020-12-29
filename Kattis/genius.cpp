#include <iostream>

int guess[1024], pp[8];
double dp[1024][1024];

int main()
{
	int m, n, p, q, i, j, r, s;
	double wr, lr, ans;
	while (scanf("%d%d%d%d%d", &m, &n, &p, &q, &guess[1]) == 5)
	{
		for (i=2; i<=n; i++)
		{
			guess[i] = (guess[i-1] * p) % q;
		}
		dp[0][0] = 1;
		for (i=1; i<=n; i++)
		{
			scanf("%d%d%d%d", &pp[0], &pp[1], &pp[2], &pp[3]);
			r = (guess[i] & 3);
			wr = (double)pp[r] / (pp[r]+pp[r^1]);
			s = ((r+2) & 3);
			wr *= (double)pp[s] / (pp[s]+pp[s^1]) * pp[r] / (pp[s]+pp[r])
					+ (double)pp[s^1] / (pp[s]+pp[s^1]) * pp[r] / (pp[s^1]+pp[r]);
			lr = 1-wr;
			dp[i][0] = dp[i-1][0] * lr;
			for (j=1; j<=i; j++)
			{
				dp[i][j] = dp[i-1][j] * lr + dp[i-1][j-1] * wr;
			}
		}
		for (i=m, ans=0; i<=n; i++)
		{
			ans += dp[n][i];
		}
		printf("%.10lf\n", ans);
	}
	return 0;
}
