#include <iostream>
#include <cstring>
using namespace std;

int cnt[8];
double dp[305][305][305];

int main()
{
	int n, i, j, k, t;
	while (scanf("%d", &n) == 1)
	{
		memset(cnt, 0, sizeof(cnt));
		for (i=0; i<n; i++)
		{
			scanf("%d", &t);
			++cnt[t];
		}
		for (i=1; i<=n; i++)
		{
			for (j=i; j>=0; j--)
			{
				for (k=i-j; k>=0; k--)
				{
					dp[i][j][k] = 0;
					// 1 => 0
					if (j > 0)
					{
						dp[i][j][k] += (dp[i-1][j-1][k] + n*1./i) * j*1./i;
					}
					// 2 => 1
					if (j < i && k > 0)
					{
						dp[i][j][k] += (dp[i][j+1][k-1] + n*1./i) * k*1./i;
					}
					// 3 => 2
					if (k < i && i-j-k > 0)
					{
						dp[i][j][k] += (dp[i][j][k+1] + n*1./i) * (i-j-k)*1./i;
					}
				}
			}
		}
		printf("%.10lf\n", dp[n][cnt[1]][cnt[2]]);
	}
	return 0;
}
