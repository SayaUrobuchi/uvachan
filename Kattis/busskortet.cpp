#include <iostream>
using namespace std;

const int N = 20005;

int dp[N];
int ary[] = {100, 200, 500};

int main()
{
	int n, i, j;
	scanf("%d", &n);
	for (i=1; ; i++)
	{
		dp[i] = 1e9;
		for (j=0; j<3; j++)
		{
			if (i >= ary[j])
			{
				dp[i] = min(dp[i], dp[i-ary[j]]+1);
			}
		}
		if (i >= n && dp[i] <= n)
		{
			printf("%d\n", dp[i]);
			break;
		}
	}
	return 0;
}
