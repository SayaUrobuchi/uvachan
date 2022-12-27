#include <iostream>
using namespace std;

int ary[512];
int dp[512][512];

int main()
{
	int n, i, j, k, l, best;
	while (cin >> n)
	{
		n <<= 1;
		for (i=1; i<=n; i++)
		{
			cin >> ary[i];
		}
		for (i=2; i<=n; i++)
		{
			for (k=i-1; k>=1; k-=2)
			{
				for (j=i-1, best=1e9; j>=k; j-=2)
				{
					best = min(best, dp[k][j-1]+dp[j+1][i-1]+abs(ary[i]-ary[j]));
				}
				dp[k][i] = best;
			}
		}
		cout << dp[1][n] << "\n";
	}
	return 0;
}
