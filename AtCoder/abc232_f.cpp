#include <iostream>
using namespace std;

int n;
int ary[20], bry[20];
long long a, b;
long long dp[20][1048576];
bool used[20][1048576];

long long recurs(int stat, int cur)
{
	int i;
	long long cost;
	if (cur < 0)
	{
		return 0;
	}
	if (used[cur][stat])
	{
		return dp[cur][stat];
	}
	used[cur][stat] = true;
	dp[cur][stat] = 9e18;
	for (i=n-1, cost=0; i>=0; i--)
	{
		if (stat & (1<<i))
		{
			dp[cur][stat] = min(dp[cur][stat], cost+recurs(stat^(1<<i), cur-1)+abs(ary[i]-bry[cur])*(long long)a);
			cost += b;
		}
	}
	return dp[cur][stat];
}

int main()
{
	int i;
	scanf("%d%lld%lld", &n, &a, &b);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	for (i=0; i<n; i++)
	{
		scanf("%d", &bry[i]);
	}
	printf("%lld\n", recurs((1<<n)-1, n-1));
	return 0;
}