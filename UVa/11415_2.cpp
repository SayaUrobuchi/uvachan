#include <stdio.h>
#include <math.h>

#define N 2703665

int tbl[N];
int dp[N];

int main()
{
	int count, n, i, j, k, sq, ans,left, right, center;
	for(i=2; i<N; i+=2)
	{
		tbl[i] = 2;
	}
	sq = (int)sqrt((double)N) + 1;
	for(i=3; i<sq; i+=2)
	{
		if(!tbl[i])
		{
			for(j=i*i, k=i+i; j<N; j+=k)
			{
				tbl[j] = i;
			}
		}
	}
	for(i=2; i<N; i++)
	{
		if(tbl[i])
		{
			tbl[i] = tbl[i/tbl[i]] + 1;
		}
		else
		{
			tbl[i] = 1;
		}
		dp[i] = tbl[i] + dp[i-1];
	}
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(left=0, right=N-1, ans=0; left<=right; )
		{
			center = left + right;
			center /= 2;
			if(dp[center] <= n)
			{
				ans = center;
				left = center + 1;
			}
			else
			{
				right = center - 1;
			}
		}
		printf("%d\n", ans+1);
	}
	return 0;
}
