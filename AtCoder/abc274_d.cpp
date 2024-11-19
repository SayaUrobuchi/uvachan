#include <iostream>
using namespace std;

const int AN = 1005;
const int N = 10020;
const int N2 = N + N;

int ary[AN];
bool dp[AN][N2+20];

int main()
{
	int n, i, j, ex, ey;
	scanf("%d%d%d", &n, &ex, &ey);
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[i]);
	}
	dp[0][0+N] = true;
	dp[1][ary[1]+N] = true;
	for (i=2; i<=n; i++)
	{
		for (j=-N+10; j<N-10; j++)
		{
			dp[i][j+N] = (dp[i-2][j-ary[i]+N] || dp[i-2][j+ary[i]+N]);
		}
	}
	if (n & 1)
	{
		swap(ex, ey);
	}
	if (dp[n][ey+N] && dp[n-1][ex+N])
	{
		puts("Yes");
	}
	else
	{
		puts("No");
	}
	return 0;
}
