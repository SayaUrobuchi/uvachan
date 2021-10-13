#include <iostream>
using namespace std;

int ucnt;
int ary[1048576], bry[1048576], tbl[1048576];
int dp[1048576][32];

int main()
{
	int n, m, i, j, k;
	while (cin >> n >> m)
	{
		for (i=0; i<n; i++)
		{
			cin >> ary[i];
		}
		++ucnt;
		for (i=0, j=0; i<n; i++)
		{
			for (; j<n&&tbl[ary[j]]!=ucnt; j++)
			{
				tbl[ary[j]] = ucnt;
			}
			bry[i] = j;
			tbl[ary[i]] = 0;
		}
		for (i=0; i<=m; i++)
		{
			dp[n][i] = 0;
		}
		for (i=n-1; i>=0; i--)
		{
			for (k=m; k>0; k--)
			{
				dp[i][k] = max(dp[i+1][k], dp[bry[i]][k-1]+bry[i]-i);
			}
		}
		cout << dp[0][m] << "\n";
	}
	return 0;
}
