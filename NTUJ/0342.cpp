#include <stdio.h>
#include <math.h>

int dp[2000005];
char used[2000005];

int recursion(int now)
{
	int i, j, temp;
	if(used[now])
	{
		return dp[now];
	}
	used[now] = 1;
	if(now < 3)
	{
		return dp[now]=now;
	}
	for(i=2, j=sqrt(now)+1, temp=now; i<j; i++)
	{
		if(now % i == 0)
		{
			if(i > 2)
			{
				temp = i;
				break;
			}
			else
			{
				if(now / i > 2)
				{
					temp = now / i;
				}
			}
		}
	}
	for(j=now-1, temp=now-now/temp; j>temp; j--)
	{
		if(recursion(j) > temp)
		{
			temp = recursion(j);
		}
	}
	return dp[now]=temp;
}

int main()
{
	int count, n, m, i;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		for(i=n; m; i++)
		{
			if(recursion(i) >= n)
			{
				m--;
				if(m == 0)
				{
					break;
				}
				n = i--;
			}
		}
		printf("%d\n", i);
	}
	return 0;
}
