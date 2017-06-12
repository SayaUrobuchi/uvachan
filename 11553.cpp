#include <stdio.h>
#include <string.h>

int used[600][600], ary[10][10], dp[600][600], n;

int recursion(int p, int q, int d)
{
	int i, j, res, temp;
	if(used[p][q])
	{
		return dp[p][q];
	}
	used[p][q] = 1;
	if(p == (1<<n)-1 && q == (1<<n)-1)
	{
		return dp[p][q] = 0;
	}
	if(d == 1)
	{
		for(i=0, res=-2147483647; i<n; i++)
		{
			if((p & (1<<i)) == 0)
			{
				temp = -recursion(p+(1<<i), q, -d);
				for(j=0; j<n; j++)
				{
					if(q & (1<<j))
					{
						temp += ary[i][j] * 2;
					}
				}
				if(temp > res)
				{
					res = temp;
				}
			}
		}
	}
	else
	{
		for(i=0, res=-2147483647; i<n; i++)
		{
			if((q & (1<<i)) == 0)
			{
				temp = -recursion(p, q+(1<<i), -d);
				for(j=0; j<n; j++)
				{
					if(p & (1<<j))
					{
						temp += ary[j][i] * 2;
					}
				}
				if(temp > res)
				{
					res = temp;
				}
			}
		}
	}
	return dp[p][q] = temp;
}

int main()
{
	int count, i, j;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				scanf("%d", &ary[i][j]);
			}
		}
		memset(used, 0, sizeof(used));
		printf("%d\n", recursion(0, 0, 1));
	}
	return 0;
}
