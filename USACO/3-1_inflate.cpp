/*
	ID: sa072682
	LANG: C
	TASK: inflate
*/
#include <stdio.h>

int dp[10001];
char chk[10001];

int main()
{
	int n, m, i, v, c, ans;
	freopen("inflate.in", "r", stdin);
	freopen("inflate.out", "w", stdout);
	scanf("%d%d", &n, &m);
	chk[0] = 1;
	ans = 0;
	while(m--)
	{
		scanf("%d%d", &v, &c);
		for(i=c; i<=n; i++)
		{
			if(chk[i-c])
			{
				if(!chk[i] || dp[i] < dp[i-c] + v)
				{
					dp[i] = dp[i-c] + v;
					chk[i] = 1;
					if(ans < dp[i])
					{
						ans = dp[i];
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	scanf(" ");
	return 0;
}
