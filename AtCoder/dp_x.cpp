#include <stdio.h>
#include <algorithm>

const int N = 1024;
const int M = 16384;

int idx[N], wei[N], str[N], val[N];
long long dp[M];

bool comp(int p, int q)
{
	//return std::min(str[p]-wei[q], str[q]) > std::min(str[q]-wei[p], wei[p]);
	return str[p]-wei[q] > str[q]-wei[p];
}

int main()
{
	int n, i, j, cur, nxt, mx;
	long long ans;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			idx[i] = i;
			scanf("%d%d%d", &wei[i], &str[i], &val[i]);
		}
		std::sort(idx, idx+n, comp);
		mx = -1;
		ans = -1;
		for (i=1; i<=n; i++)
		{
			cur = idx[i-1];
			//printf(".. %d\n", cur);
			for (j=wei[cur]; j<=mx; j++)
			{
				nxt = std::min(j-wei[cur], str[cur]);
				if (dp[j] != -1 && dp[nxt] < dp[j] + val[cur])
				{
					dp[nxt] = dp[j] + val[cur];
					if (ans < dp[nxt])
					{
						ans = dp[nxt];
					}
				}
			}
			if (dp[str[cur]] < val[cur])
			{
				dp[str[cur]] = val[cur];
				for (mx++; mx<str[cur]; mx++)
				{
					dp[mx] = -1;
				}
				if (ans < dp[str[cur]])
				{
					ans = dp[str[cur]];
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
