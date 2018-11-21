#include <stdio.h>

int dp[105][105][105];
char s[18][105];

int max(int p, int q)
{
	return p>q?p:q;
}

int main()
{
	int n, i, j, k, p, q, r, ans;
	while(scanf("%d", &n) == 1)
	{
		for(i=0, ans=0; i<n; i++)
		{
			scanf("%s", s[i]+1);
			for(j=0; j<i; j++)
			{
				for(k=0; k<j; k++)
				{
					for(p=1; s[i][p]; p++)
					{
						for(q=1; s[j][q]; q++)
						{
							for(r=1; s[k][r]; r++)
							{
								if(s[i][p] == s[j][q] && s[i][p] == s[k][r])
								{
									dp[p][q][r] = dp[p-1][q-1][r-1]+1;
								}
								else
								{
									dp[p][q][r] = max(dp[p-1][q][r], max(dp[p][q-1][r], dp[p][q][r-1]));
								}
							}
						}
					}
					ans = max(ans, dp[p-1][q-1][r-1]);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
