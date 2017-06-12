#include <stdio.h>
#include <stdlib.h>

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
	int cas, n, i, j, k, sq;
	cas = 0;
	for(k=4; k<=2000000; k+=2)
	{
		dp[k] = k >> 1;
	}
	for(i=3; i<1500; i+=2)
	{
		if(!dp[i])
		{
			for(k=i*i, j=i+i; k<=2000000; k+=j)
			{
				if(!dp[k])
				{
					dp[k] = k / i;
				}
			}
		}
	}
	ary[1] = 1;
	for(i=2; i<=2000000; i++)
	{
		ary[i] = i;
		dp[i] = dp[dp[i]] + 1;
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
