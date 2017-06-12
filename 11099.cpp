#include <stdio.h>
#include <string.h>

int prime[168];
int tbl[1001];
int ary[168];
int loc[168];
long long dp[10001];

int main()
{
	int n, m, i, j, k, s, temp2, min;
	long long temp;
	prime[0] = 2;
	for(i=3, j=1; i<35; i+=2)
	{
		if(!tbl[i])
		{
			prime[j++] = i;
			for(k=i*i, s=i+i; k<1000; k+=s)
			{
				tbl[k] = 1;
			}
		}
	}
	for(; i<1000; i+=2)
	{
		if(!tbl[i])
		{
			prime[j++] = i;
		}
	}
	m = j;
	while(scanf("%d", &n) == 1)
	{
		if(n == 1)
		{
			printf("Not Exist!\n");
			continue;
		}
		for(i=0, j=0, dp[0]=1, temp=n; i<m; i++)
		{
			if(!(temp%prime[i]))
			{
				for(temp/=prime[i]; !(temp%prime[i]); temp/=prime[i]);
				ary[j++] = prime[i];
				dp[0] *= prime[i];
			}
		}
		if(temp > 1)
		{
			ary[j++] = temp;
			dp[0] *= temp;
		}
		memset(loc, 0, sizeof(loc));
		for(i=1; ; i++)
		{
			for(k=0, min=2147483647; k<j; k++)
			{
				for(; (temp=dp[loc[k]]*ary[k])<=dp[i-1]; loc[k]++);
				if(temp < min)
				{
					min = temp;
					temp2 = k;
				}
			}
			if(min > n)
			{
				break;
			}
			dp[i] = min;
			loc[temp2]++;
		}
		if(min > 2000000)
		{
			printf("Not Exist!\n");
		}
		else
		{
			printf("%d\n", min);
		}
	}
	return 0;
}
