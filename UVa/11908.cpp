#include<iostream>
#include <algorithm>
using namespace std;

int dp[200005], st[30005], ed[30005], cost[30005], idx[30005];

bool comp(int p, int q)
{
	return ed[p] < ed[q];
}

int main() {
	int count, cas, n, i, j;
	cas = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=0; i<n; i++)
		{
			scanf("%d%d%d", &st[i], &ed[i], &cost[i]);
			ed[i] += st[i];
			st[i]++;
			idx[i] = i;
		}
		sort(idx, idx+n, comp);
		for (i=1, j=0; j<n; i++)
		{
			dp[i] = dp[i-1];
			while (j<n && ed[idx[j]] == i)
			{
				dp[i] = max(dp[i], (dp[st[idx[j]]-1] + cost[idx[j]]));
				j++;
			}
		}
		printf("Case %d: %d\n", ++cas, dp[i-1]);
	}
	return 0;
}

