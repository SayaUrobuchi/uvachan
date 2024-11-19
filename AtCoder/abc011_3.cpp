#include <iostream>
using namespace std;

const int N = 512;

int tbl[N], dp[N];

int main()
{
	int n, i, j;
	scanf("%d", &n);
	for (i=0; i<3; i++)
	{
		int t;
		scanf("%d", &t);
		tbl[t] = true;
	}
	for (i=1; i<=n; i++)
	{
		if (tbl[i])
		{
			dp[i] = 201;
		}
		else
		{
			dp[i] = dp[i-1] + 1;
			for (j=i-2; j>=0&&j>=i-3; j--)
			{
				dp[i] = min(dp[i], dp[j] + 1);
			}
		}
	}
	if (dp[n] <= 100)
	{
		puts("YES");
	}
	else
	{
		puts("NO");
	}
	return 0;
}
