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
	int cas, n, i, j, k, sq;
	cas = 0;
	for(i=1; i<=2000000; i++)
	{
		ary[i] = i;
	}
	for(j=2; j<=2000000; j<<=1)
	{
		for(k=j; k<=2000000; k+=j)
		{
			dp[k]++;
		}
	}
	for(i=3; i<130; i+=2)
	{
		if(!dp[i])
		{
			for(j=i; j<=2000000; j*=i)
			{
				for(k=j; k<=2000000; k+=j)
				{
					dp[k]++;
				}
			}
		}
	}
	for(; i<1500; i+=2)
	{
		if(!dp[i])
		{
			j = i;
			for(k=j; k<=2000000; k+=j)
			{
				dp[k]++;
			}
			j *= i;
			for(k=j; k<=2000000; k+=j)
			{
				dp[k]++;
			}
		}
	}
	for(; i<=2000000; i+=2)
	{
		if(!dp[i])
		{
			for(j=i; j<=2000000; j+=i)
			{
				dp[j]++;
			}
		}
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
