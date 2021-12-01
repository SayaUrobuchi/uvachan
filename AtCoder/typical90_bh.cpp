#include <iostream>
#include <algorithm>
using namespace std;

int ary[1048576], bry[1048576], dp[1048576];

int main()
{
	int n, i, t, sn, ans;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, sn=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			t = lower_bound(dp, dp+sn, ary[i]) - dp;
			dp[t] = ary[i];
			sn = max(sn, t+1);
			bry[i] = t+1;
		}
		for (i=n-1, ans=1, sn=0; i>=0; i--)
		{
			t = lower_bound(dp, dp+sn, ary[i]) - dp;
			dp[t] = ary[i];
			sn = max(sn, t+1);
			ans = max(ans, bry[i]+t);
		}
		printf("%d\n", ans);
	}
	return 0;
}
