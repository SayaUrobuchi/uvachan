#include <stdio.h>

int main()
{
	int cas, n, m, i, dp[8], ans;
	char buf[10], order[7], str[257];
	cas = 0;
	dp[1] = 1;
	for(i=2; i<8; i++)
	{
		dp[i] = dp[i-1] * 2;
	}
	while(scanf("%d", &n) == 1)
	{
		if(!n) break;
		for(i=0; i<n; i++)
		{
			scanf("%s", buf);
			order[i] = buf[1] - 49;
		}
		scanf("%s%d", str, &m);
		printf("S-Tree #%d:\n", ++cas);
		while(m--)
		{
			scanf("%s", buf);
			for(i=0, ans=0; i<n; i++)
			{
				if(buf[order[i]] == 49)
				{
					ans += dp[n-i];
				}
			}
			printf("%c", str[ans]);
		}
		printf("\n\n");
	}
	return 0;
}