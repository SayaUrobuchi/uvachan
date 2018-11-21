#include <stdio.h>
#include <string.h>

int conn1[26], conn2[26];
int dp[31][26];
int tbl[26];
char str[100];

int main()
{
	int n, m, i, j, ans;
	while(scanf("%d", &n) == 1)
	{
		gets(str);
		for(i=0; i<n; i++)
		{
			gets(str);
			str[0] -= 65;
			tbl[str[0]] = (str[6] == 'x');
			conn1[str[0]] = str[2] - 65;
			conn2[str[0]] = str[4] - 65;
		}
		scanf("%d", &m);
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1 << m;
		for(i=1; i<=m; i++)
		{
			for(j=0; j<n; j++)
			{
				dp[i][conn1[j]] += (dp[i-1][j] >> 1);
				dp[i][conn2[j]] += (dp[i-1][j] >> 1);
			}
		}
		for(i=0, ans=0; i<n; i++)
		{
			if(tbl[i])
			{
				ans += dp[m][i];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
