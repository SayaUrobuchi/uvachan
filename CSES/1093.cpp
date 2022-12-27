#include <iostream>
using namespace std;

const int M = 1000000007;

int dp[250005];

int main()
{
	int n, i, j, t;
	while (scanf("%d", &n) == 1)
	{
		t = (1+n)*n/2;
		if (t & 1)
		{
			puts("0");
		}
		else
		{
			t >>= 1;
			for (i=2; i<=t; i++)
			{
				dp[i] = 0;
			}
			dp[1] = 1;
			for (i=2; i<=n; i++)
			{
				for (j=t; j>i; j--)
				{
					dp[j] = (dp[j] + dp[j-i]) % M;
				}
			}
			printf("%d\n", dp[t]);
		}
	}
	return 0;
}

