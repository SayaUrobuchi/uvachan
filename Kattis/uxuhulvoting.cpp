#include <iostream>
using namespace std;

const int N = 105;
const int M = 8;

int tbl[N][M];
int dp[N][M];

int main()
{
	int count;
	scanf("%d", &count);
	while (count--)
	{
		int n, i, j, k;
		scanf("%d", &n);
		for (i=0; i<n; i++)
		{
			for (j=0; j<M; j++)
			{
				int t;
				scanf("%d", &t);
				tbl[i][j] = t;
			}
		}
		for (i=0; i<M; i++)
		{
			dp[n][i] = i;
		}
		for (i=n-1; i>=0; i--)
		{
			for (j=0; j<M; j++)
			{
				int best = M + M;
				int best_stat;
				for (k=0; k<3; k++)
				{
					int t = (j ^ (1 << k));
					int res = tbl[i][ dp[i+1][t] ];
					if (res < best)
					{
						best = res;
						best_stat = dp[i+1][t];
					}
				}
				dp[i][j] = best_stat;
				//printf(".. %d: %d => %d\n", i, j, dp[i][j]);
			}
		}
		int ans = dp[0][0];
		char s[4] = {};
		for (i=2; i>=0; i--, ans>>=1)
		{
			s[i] = "NY"[ans&1];
		}
		puts(s);
	}
	return 0;
}