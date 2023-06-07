#include <iostream>
using namespace std;

const int CN = 4;
const int M = 100005;

int val[CN+1], cnt[CN+1];
long long dp[CN+1][M];

int main()
{
	int count, i, j, m, o, t, sum, coe;
	long long ans;
	scanf("%d", &count);
	while (count--)
	{
		for (i=1; i<=CN; i++)
		{
			scanf("%d", &val[i]);
		}
		dp[0][0] = 1;
		for (i=1; i<M; i++)
		{
			dp[0][i] = 0;
		}
		for (i=1; i<=CN; i++)
		{
			for (j=0; j<M; j++)
			{
				dp[i][j] = dp[i-1][j];
				if (j >= val[i])
				{
					dp[i][j] += dp[i][j-val[i]];
				}
			}
		}
		scanf("%d", &o);
		while (o--)
		{
			for (i=1; i<=CN; i++)
			{
				scanf("%d", &cnt[i]);
			}
			scanf("%d", &m);
			for (i=0, ans=0; i<(1<<CN); i++)
			{
				for (j=0, t=0, sum=0; j<CN; j++)
				{
					if (i & (1 << j))
					{
						++t;
						sum += val[j+1] * (cnt[j+1] + 1);
					}
				}
				coe = (t & 1) ? -1 : 1;
				ans += (sum > m ? 0LL : dp[CN][m-sum]) * coe;
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}
