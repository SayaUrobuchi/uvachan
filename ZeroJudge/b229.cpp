#include <iostream>

unsigned long long dp[64][4];

int main()
{
	int n, i;
	dp[0][0] = 1;
	for (i=1; i<=52; i++)
	{
		dp[i][0] = dp[i-1][0] + (dp[i-1][1]<<1);
		dp[i][1] = dp[i-1][0] + dp[i-1][1];
	}
	while (std::cin >> n)
	{
		std::cout << dp[n+1][0] << "\n";
	}
	return 0;
}
