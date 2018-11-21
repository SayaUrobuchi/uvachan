#include <stdio.h>
#include <string.h>

int ary[10000], n;
char dp[101], temp[101];

int mod(int num)
{
	if(num >= n)
	{
		return num % n;
	}
	else if(num < 0)
	{
		return -(num % n);
	}
	return num;
}

int main()
{
	int count, m, in, i;
	while(scanf("%d%d%d", &m, &n, &in) == 3)
	{
		memset(dp, 0, sizeof(dp));
		dp[mod(in)] = 1;
		while(--m)
		{
			scanf("%d", &in);
			for(i=0; i<n; i++)
			{
				if(dp[i])
				{
					temp[mod(i+in)] = 1;
					temp[mod(i-in)] = 1;
				}
			}
			memcpy(dp, temp, n);
			memset(temp, 0, sizeof(temp));
		}
		if(dp[0])
		{
			printf("Divisible\n");
		}
		else
		{
			printf("Not divisible\n");
		}
	}
	return 0;
}
