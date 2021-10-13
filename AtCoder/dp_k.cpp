#include <iostream>
using namespace std;

int ary[128];
int dp[1048576];

int main()
{
	int n, m, i, j;
	bool f;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		dp[0] = false;
		for (i=1; i<=m; i++)
		{
			f = false;
			for (j=0; j<n&&!f; j++)
			{
				if (i >= ary[j])
				{
					if (!dp[i-ary[j]])
					{
						f = true;
					}
				}
			}
			dp[i] = f;
		}
		puts(dp[m] ? "First" : "Second");
	}
	return 0;
}
