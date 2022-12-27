#include <iostream>
using namespace std;

const int N = 1024;

int price[N], pages[N];
int dp[131072];

int main()
{
	int n, m, i, j;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &price[i]);
		}
		for (i=0; i<n; i++)
		{
			scanf("%d", &pages[i]);
		}
		for (i=0; i<=m; i++)
		{
			dp[i] = 0;
		}
		for (i=0; i<n; i++)
		{
			for (j=m; j>=price[i]; j--)
			{
				dp[j] = max(dp[j-price[i]]+pages[i], dp[j]);
			}
		}
		printf("%d\n", dp[m]);
	}
	return 0;
}

