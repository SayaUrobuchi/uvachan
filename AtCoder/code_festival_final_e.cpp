#include <iostream>
using namespace std;

const int N = 3005;

int ary[N], dp[N][2];

int main()
{
	int n, i, j;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	int ans = 1;
	dp[0][0] = 1;
	dp[0][1] = 1;
	for (i=1; i<n; i++)
	{
		dp[i][0] = 1;
		dp[i][1] = 1;
		for (j=0; j<i; j++)
		{
			if (ary[j] < ary[i])
			{
				dp[i][0] = max(dp[i][0], dp[j][1] + 1);
			}
			else if (ary[j] > ary[i])
			{
				dp[i][1] = max(dp[i][1], dp[j][0] + 1);
			}
		}
		ans = max(ans, max(dp[i][0], dp[i][1]));
	}
	if (ans < 3)
	{
		ans = 0;
	}
	printf("%d\n", ans);
	return 0;
}
