#include <iostream>
using namespace std;

const int T = 10000;

int dp[T+5];

int main()
{
	int n, i, j, k, w, v, c;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d%d%d", &w, &v, &c);
		for (j=1; c>0; c-=j, j<<=1)
		{
			int rc = min(j, c);
			int rw = w * rc;
			int rv = v * rc;
			for (k=T; k>=rw; k--)
			{
				dp[k] = max(dp[k], dp[k-rw] + rv);
			}
		}
	}
	scanf("%d", &w);
	printf("%d\n", dp[w]);
	return 0;
}
