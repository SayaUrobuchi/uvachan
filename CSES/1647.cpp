#include <iostream>
using namespace std;
 
int dp[20][200005];
 
int main()
{
	int n, m, i, j, a, b;
	scanf("%d%d", &n, &m);
	for (i=1; i<=n; i++)
	{
		scanf("%d", &dp[0][i]);
	}
	for (i=1; (1<<i)<=n; i++)
	{
		for (j=1; j+(1<<i)-1<=n; j++)
		{
			dp[i][j] = min(dp[i-1][j], dp[i-1][j+(1<<(i-1))]);
		}
	}
	for (i=0; i<m; i++)
	{
		scanf("%d%d", &a, &b);
		for (j=1; (1<<j)<=b-a+1; j++);
		--j;
		printf("%d\n", min(dp[j][a], dp[j][b-(1<<j)+1]));
	}
	return 0;
}
