#include <iostream>
using namespace std;

const int N = 2000005;
const int K = 30;

int ary[N];
long long dp[N];
//__int128_t dp[N];

void pp(__int128_t t)
{
	if (t > 9)
	{
		pp(t / 10);
	}
	printf("%d", (int)(t%10));
}

int main()
{
	int n, i, j;
	scanf("%d", &n);
	for (i=0; i<=n; i++)
	{
		scanf("%d", &ary[i]);
	}
	dp[0] = 0;
	for (i=1; i<=n; i++)
	{
		dp[i] = 9e18;
		//dp[i] = (9e18 * 9e18);
		for (j=1; i-j>=0&&j<=K; j++)
		{
			//long long c = (1LL << (j-1)) * ary[i] * ary[i-j];
			long long c = ary[i] * 1LL * ary[i-j];
			if ((1LL << (j-1)) > 9e18 / c)
			{
				break;
			}
			c *= (1LL << (j-1));
			//__int128_t c = (__int128_t)(1LL << (j-1)) * ary[i] * ary[i-j];
			if (c < dp[i] - dp[i-j])
			{
				dp[i] = min(dp[i], dp[i-j]+c);
			}
		}
	}
	printf("%lld\n", dp[n]);
	//pp(dp[n]);
	//puts("");
	return 0;
}
