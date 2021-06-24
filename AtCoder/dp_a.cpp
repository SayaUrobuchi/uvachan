#include <iostream>
using namespace std;

int ary[131072], dp[131072];

int main()
{
	int n, i;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		dp[0] = 0;
		dp[1] = abs(ary[1]-ary[0]);
		for (i=2; i<n; i++)
		{
			dp[i] = min(dp[i-1]+abs(ary[i]-ary[i-1]), dp[i-2]+abs(ary[i]-ary[i-2]));
		}
		printf("%d\n", dp[n-1]);
	}
	return 0;
}
