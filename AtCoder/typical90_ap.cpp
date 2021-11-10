#include <iostream>
#include <cstring>
using namespace std;

const int M = 1e9+7;

int dp[10];

int main()
{
	int n, i, j, t;
	while (scanf("%d", &n) == 1)
	{
		if (n % 9)
		{
			puts("0");
			continue;
		}
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (i=1, t=dp[0]; i<=n; t=(t-dp[i%10]+M)%M, dp[i%10]=t, t=(t+dp[i%10])%M, i++, j++);
		printf("%d\n", dp[n%10]);
	}
	return 0;
}
