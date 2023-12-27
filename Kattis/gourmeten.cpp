#include <iostream>
using namespace std;

const int N = 32;
const int M = 1024;

int ary[N];
int dp[M];

int main()
{
	int n, m, i, j;
	scanf("%d%d", &m, &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	dp[0] = 1;
	for (i=1; i<=m; i++)
	{
		for (j=0; j<n; j++)
		{
			if (i >= ary[j])
			{
				dp[i] += dp[i-ary[j]];
			}
		}
	}
	printf("%d\n", dp[m]);
	return 0;
}
