#include <iostream>
using namespace std;

const int N = 1024;

int ary[N][N], dp[N][N];

int main()
{
	int n, m, o, i, j, p, q, mid, ans;
	bool ok;
	while (scanf("%d%d", &n, &m) == 2)
	{
		o = m*m/2 + 1;
		o = m*m - o;
		for (i=1; i<=n; i++)
		{
			for (j=1; j<=n; j++)
			{
				scanf("%d", &ary[i][j]);
			}
		}
		for (p=0, q=1e9, ans=0; p<=q; )
		{
			mid = ((p+q) >> 1);
			for (i=1, ok=false; i<=n; i++)
			{
				for (j=1; j<=n; j++)
				{
					dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + (ary[i][j] <= mid);
					if (i >= m && j >= m && dp[i][j] - dp[i-m][j] - dp[i][j-m] + dp[i-m][j-m] > o)
					{
						ok = true;
					}
				}
			}
			if (ok)
			{
				ans = mid;
				q = mid - 1;
			}
			else
			{
				p = mid + 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

