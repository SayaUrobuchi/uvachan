#include <iostream>
#include <algorithm>
using namespace std;

int ary[100005], days[15], price[15], spday[100005];
int dp[500005];

int main()
{
	int n, m, o, i, j, k, idx;
	scanf("%d%d%d", &n, &m, &o);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	for (i=0; i<m; i++)
	{
		scanf("%d", &days[i]);
	}
	for (i=0; i<m; i++)
	{
		scanf("%d", &price[i]);
	}
	for (i=0; i<o; i++)
	{
		scanf("%d", &spday[i]);
	}
	for (i=1, j=0; i<=ary[n-1]; i++)
	{
		if (i != ary[j])
		{
			dp[i] = dp[i-1];
			continue;
		}
		dp[i] = 2e9;
		for (k=0; k<m; k++)
		{
			dp[i] = min(dp[i], dp[max(0, i-days[k])]+price[k]);
			idx = upper_bound(spday, spday+o, i-days[k]) - spday;
			if (idx < o && spday[idx] <= i)
			{
				dp[i] = min(dp[i], dp[spday[idx]-1]+(price[k]>>1));
			}
		}
		j++;
	}
	printf("%d\n", dp[ary[n-1]]);
	return 0;
}