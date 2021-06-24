#include <iostream>
using namespace std;

int ary[131072], dp[131072];

int main()
{
	int n, i, j, k;
	while (scanf("%d%d", &n, &k) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		dp[0] = 0;
		for (i=1; i<n; i++)
		{
			dp[i] = 2e9;
			for (j=i-1; j>=0&&j>=i-k; j--)
			{
				dp[i] = min(dp[j]+abs(ary[i]-ary[j]), dp[i]);
			}
		}
		printf("%d\n", dp[n-1]);
	}
	return 0;
}
