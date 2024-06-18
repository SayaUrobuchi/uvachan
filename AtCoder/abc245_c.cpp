#include <iostream>
using namespace std;

const int N = 200005;

int ary[N], bry[N];
bool dp[N][2];

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	for (i=0; i<n; i++)
	{
		scanf("%d", &bry[i]);
	}
	dp[0][0] = dp[0][1] = true;
	for (i=1; i<n; i++)
	{
		if (abs(ary[i]-ary[i-1]) <= m)
		{
			dp[i][0] |= dp[i-1][0];
		}
		if (abs(ary[i]-bry[i-1]) <= m)
		{
			dp[i][0] |= dp[i-1][1];
		}
		if (abs(bry[i]-ary[i-1]) <= m)
		{
			dp[i][1] |= dp[i-1][0];
		}
		if (abs(bry[i]-bry[i-1]) <= m)
		{
			dp[i][1] |= dp[i-1][1];
		}
	}
	puts((dp[n-1][0]||dp[n-1][1]) ? "Yes" : "No");
	return 0;
}
