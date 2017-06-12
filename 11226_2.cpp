#include <stdio.h>
#include <string.h>

char dp[500001];
int tbl[500001];

int main()
{
	int cas, count, n, m, i, j, k;
	cas = 0;
	for(i=2; i<708; i++)
	{
		if(tbl[i])
		{
			tbl[i] += tbl[i/tbl[i]];
			dp[i] = dp[tbl[i]] + 1;
		}
		else
		{
			dp[i] = 1;
			tbl[i] = i;
			for(j=i*i; j<500001; j+=i)
			{
				if(!tbl[j])
				{
					tbl[j] = i;
				}
			}
		}
	}
	for(; i<500001; i++)
	{
		if(tbl[i])
		{
			tbl[i] += tbl[i/tbl[i]];
			dp[i] = dp[tbl[i]] + 1;
		}
		else
		{
			dp[i] = 1;
			tbl[i] = i;
		}
	}
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		if(n > m)
		{
			m ^= n ^= m ^= n;
		}
		for(i=n, m++, j=0; i<m; i++)
		{
			if(dp[i] > j)
			{
				j = dp[i];
			}
		}
		printf("Case #%d:\n%d\n", ++cas, j);
	}
	return 0;
}
