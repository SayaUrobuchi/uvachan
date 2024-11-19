#include <iostream>
using namespace std;

const int N = 8;
const int BITN = 128;

int dp[N][BITN];

int main()
{
	int n, m, i, j, k;
	scanf("%d%d", &n, &m);
	dp[0][0] = true;
	for (i=1; i<=n; i++)
	{
		for (j=0; j<m; j++)
		{
			int t;
			scanf("%d", &t);
			for (k=0; k<128; k++)
			{
				dp[i][k] |= dp[i-1][k^t];
			}
		}
	}
	puts(dp[n][0] ? "Found" : "Nothing");
	return 0;
}
