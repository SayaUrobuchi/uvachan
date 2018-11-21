#include <stdio.h>

int ary[100005], dp[50005][1005], dp2[50005][1005];

int main()
{
	int n, m, i, j, k, l, p, q, c, r, sum, mx, cnt, ans;
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(i=1, sum=0, mx=0; i<=n; i++)
		{
			scanf("%d", &ary[i]);
			sum += ary[i];
			if(ary[i] > mx)
			{
				mx = ary[i];
			}
		}
		for(p=mx, q=sum; p<=q; )
		{
			c = ((p+q)>>1);
			for(i=1, j=1, cnt=0; i<=n&&j<=m; i++)
			{
				if(cnt + ary[i] > c)
				{
					cnt = 0;
					j++;
				}
				cnt += ary[i];
			}
			if(j <= m)
			{
				r = c;
				q = c-1;
			}
			else
			{
				p = c+1;
			}
		}
		dp[0][0] = 1;
		dp2[0][0] = 1;
		for(i=1; i<=n; i++)
		{
			dp[i][0] = 0;
			dp2[i][0] = 1;
			ans = 0;
			for(k=i, cnt=ary[k]; k>0&&cnt<=r; k--, cnt+=ary[k]);
			for(j=1; j<=i&&j<=m; j++)
			{
				dp[i][j] = dp2[i-1][j-1];
				if(k)
				{
					dp[i][j] -= dp2[k-1][j-1];
				}
				ans += (dp[i][j] %= 10007);
				dp2[i][j] = dp2[i-1][j] + dp[i][j];
			}
		}
		printf("%d %d\n", r, ans%10007);
	}
	return 0;
}
