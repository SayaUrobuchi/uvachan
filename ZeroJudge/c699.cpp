#include <stdio.h>
#include <string.h>
#include <algorithm>

const int M = 1000000007;

int dp[8][1048576];
int sz[300005], attr[300005], idx[300005];

bool comp(int p, int q)
{
	return sz[p] < sz[q];
}

int main()
{
	int n, m, o, i, j, p, q, t, msk;
	while (scanf("%d%d%d", &n, &m, &o) == 3)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &sz[i]);
			idx[i] = i;
			attr[i] = 0;
			for (j=0; j<o; j++)
			{
				scanf("%d", &t);
				attr[i] |= (t << j);
			}
		}
		std::sort(idx, idx+n, comp);
		memset(dp, 0, sizeof(dp));
		msk = (1 << o);
		dp[0][0] = 1;
		for (i=0; i<n; i++)
		{
			p = sz[idx[i]];
			q = attr[idx[i]];
			for (j=0; j<msk; j++)
			{
				dp[p][j|q] = (dp[p][j|q] + dp[p-1][j]) % M;
			}
		}
		printf("%d\n", dp[m][msk-1]);
	}
	return 0;
}
