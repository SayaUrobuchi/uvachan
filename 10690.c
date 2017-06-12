#include <stdio.h>
#include <string.h>

int ary[101];
char dp[20001][51];

int main()
{
	int n, m, i, j, k, sum, temp, len, ans, ans2;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n > m)
		{
			temp = n;
			n = m;
			m = temp;
		}
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for(i=0, sum=0, len=n+m; i<len; i++)
		{
			scanf("%d", &temp);
			sum += (temp += 51);
			for(j=sum; j>=temp; j--)
			{
				for(k=1; k<=n; k++)
				{
					if(dp[j-temp][k-1])
					{
						dp[j][k] = 1;
					}
				}
			}
		}
		for(i=sum, ans=1000000000, ans2=-1000000000; i>-1; i--)
		{
			if(dp[i][n])
			{
				if((temp=(i-n*51)*(sum-i-m*51)) > ans2)
				{
					ans2 = temp;
				}
				if(temp < ans)
				{
					ans = temp;
				}
			}
		}
		printf("%d %d\n", ans2, ans);
	}
	return 0;
}
