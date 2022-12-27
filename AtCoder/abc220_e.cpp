#include <iostream>
using namespace std;

const int M = 998244353;

long long dp[1000005], dp2[1000005];

int main()
{
	int n, m, i, j;
	long long ans, t;
	dp[0] = 1;
	dp2[0] = 0;
	for (i=1; i<=1000000; i++)
	{
		dp[i] = (dp[i-1]<<1) % M;
		dp2[i] = (dp[i]-1+M) % M;
	}
	while (scanf("%d%d", &n, &m) == 2)
	{
		--n;
		for (ans=0, i=min(n, m), j=m-i; i>=j; --i, ++j)
		{
			t = dp2[n-i+1];
			t = (t * dp[i-1]) % M;
			if (j)
			{
				t = (t * dp[j-1]) % M;
			}
			else
			{
				t = (t << 1) % M;
			}
			//printf(".. %d %d => %lld\n", i, j, t);
			t = (t << 1) % M;
			if (i != j && j)
			{
				t = (t << 1) % M;
			}
			ans = (ans + t) % M;
			//printf("%d %d => %lld\n", i, j, ans);
		}
		printf("%d\n", ans);
	}
	return 0;
}

