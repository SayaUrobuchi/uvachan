#include <iostream>
using namespace std;

const int N = 262144;
const int M = 1000000007;

int dp[N], tbl[N];
char buf[N];

int main()
{
	int i;
	while (scanf("%s", buf+1) == 1)
	{
		dp[0] = 1;
		for (i='a'; i<='z'; i++)
		{
			tbl[i] = 0;
		}
		dp[1] = 2;
		tbl[buf[1]] = 1;
		for (i=2; buf[i]; i++)
		{
			dp[i] = (dp[i-1]+dp[i-2]) % M;
			dp[i] = (dp[i]-tbl[buf[i]]+M) % M;
			tbl[buf[i]] = dp[i-2];
		}
		printf("%d\n", (dp[i-1]+M-1)%M);
	}
	return 0;
}

