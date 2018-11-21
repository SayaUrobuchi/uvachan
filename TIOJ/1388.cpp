#include <stdio.h>
#include <string.h>

int used[105][105], dp[105][105], ary[105];

int recursion(int p, int q)
{
	int i, temp;
	if(used[p][q])
	{
		return dp[p][q];
	}
	used[p][q] = 1;
	if(p == q)
	{
		return dp[p][q] = ary[p];
	}
	dp[p][q] = -1;
	if((q-p+1) % 2)
	{
		for(i=p; i<q; i++)
		{
			if((temp=recursion(p, i)*recursion(i+1, q)) > dp[p][q])
			{
				dp[p][q] = temp;
			}
		}
	}
	else
	{
		for(i=p; i<q; i++)
		{
			if((temp=recursion(p, i)+recursion(i+1, q)) > dp[p][q])
			{
				dp[p][q] = temp;
			}
		}
	}
	return dp[p][q];
}

int main()
{
	int n, i;
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		memset(used, 0, sizeof(used));
		printf("%d\n", recursion(0, n-1));
	}
	return 0;
}
