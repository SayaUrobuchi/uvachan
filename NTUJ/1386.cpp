#include <stdio.h>
#include <string.h>

#define N 1000000007

int ary[10];
long long c[1005][1005], dp[10][10005];

int main()
{
	int count, i, j, k, l, o, p, sum;
	long long t, ans;
	c[0][0] = 1;
	for(i=1; i<=1000; i++)
	{
		c[i][0] = 1;
		for(j=1; j<=i; j++)
		{
			c[i][j] = (c[i-1][j-1]+c[i-1][j])%N;
		}
	}
	scanf("%d", &count);
	while(count--)
	{
		for(i=1, sum=0; i<=9; i++)
		{
			scanf("%d", &ary[i]);
			sum += ary[i];
		}
		memset(dp, 0, sizeof(dp));
		for(i=1; i<=9; i++)
		{
			dp[i][0] = 1;
			if(ary[i])
			{
				ary[i]--;
				for(l=1; l<=9; l++)
				{
					for(o=sum-1; o>=0; o--)
					{
						for(p=1; p<=ary[l]&&o-p>=0; p++)
						{
							dp[i][o] = (dp[i][o]+dp[i][o-p]*c[o][p])%N;
						}
					}
				}
				ary[i]++;
			}
		}
		for(i=1, ans=0; i<=sum; i++)
		{
			for(j=0, t=1; j<i; j++, t=(t*10)%N)
			{
				for(k=1; k<=9; k++)
				{
					if(ary[k])
					{
						ans = (ans+((dp[k][i-1]*t)%N)*k)%N;
						//printf("!!!! %d::%d %d %d .. %d %d\n", (int)ans, dp[k][i-1], (int)t, k, k, i-1);
					}
				}
			}
		}
		printf("%d\n", (int)ans);
	}
	return 0;
}
