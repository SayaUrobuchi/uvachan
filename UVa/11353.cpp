#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int dp[2000002];
int ary[2000002];

int comp(const void *p, const void *q)
{
	if(dp[*(int*)p] == dp[*(int*)q])
	{
		return *(int*)p - *(int*)q;
	}
	return dp[*(int*)p] - dp[*(int*)q];
}

int main()
{
	int cas, n, i, j, sq;
	cas = 0;
	dp[1] = 0;
	ary[1] = 1;
	for(i=2, sq=1; i<=2000000; i++)
	{
		sq += (sq*sq+sq+sq+1 == i);
		dp[i] = dp[i>>1] + 1;
		ary[i] = i;
		sq += (sq*sq+sq+sq+1 == ++i);
		for(j=3; j<=sq; j+=2)
		{
			if(!(i % j))
			{
				break;
			}
		}
		if(j > sq)
		{
			dp[i] = 1;
		}
		else
		{
			dp[i] = dp[i/j] + 1;
		}
		ary[i] = i;
	}
	qsort(ary+1, 2000000, sizeof(int), comp);
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		printf("Case %d: %d\n", ++cas, ary[n]);
	}
	return 0;
}
