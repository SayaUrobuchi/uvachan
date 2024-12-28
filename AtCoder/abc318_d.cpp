#include <iostream>
using namespace std;

const int N = 16;
const int N2N = (1 << N);

int n;
int ary[N][N];
bool used[N2N];
long long dp[N2N];

long long recurs(int stat)
{
	int i, j;
	if (used[stat])
	{
		return dp[stat];
	}
	used[stat] = true;
	if (stat == 0)
	{
		return dp[stat] = 0;
	}
	for (i=0; i<n; i++)
	{
		if ((stat >> i) & 1)
		{
			for (j=i+1; j<n; j++)
			{
				if ((stat >> j) & 1)
				{
					int nt = (stat & ~((1<<i) | (1<<j)));
					dp[stat] = max(dp[stat], recurs(nt) + ary[i][j]);
				}
			}
		}
	}
	return dp[stat];
}

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		for (j=i+1; j<n; j++)
		{
			scanf("%d", &ary[i][j]);
		}
	}
	long long ans = recurs((1<<n)-1);
	printf("%lld\n", ans);
	return 0;
}
