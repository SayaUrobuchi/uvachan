#include <iostream>
using namespace std;

const int N = 1024;
const int M = 10005;

int dmg[N], cost[N];
int dp[M];

int main()
{
	int n, m, i, j;
	scanf("%d%d", &m, &n);
	for (i=0; i<n; i++)
	{
		scanf("%d%d", &dmg[i], &cost[i]);
	}
	for (i=1; i<=m; i++)
	{
		int t = 1e9;
		for (j=0; j<n; j++)
		{
			int remain = i - dmg[j];
			int c = 0;
			if (remain > 0)
			{
				c = dp[remain];
			}
			t = min(t, cost[j] + c);
		}
		dp[i] = t;
	}
	printf("%d\n", dp[m]);
	return 0;
}
