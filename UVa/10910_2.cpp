#include <stdio.h>
#include <string.h>

int o;
int dp[71][71];

int recursion(int n, int m)
{
	int i, temp;
	if(dp[n][m])
	{
		return dp[n][m];
	}
	if(n == 1)
	{
		return m >= o;
	}
	else if(n == 2)
	{
		if(m >= o+o)
		{
			return m-(o+o)+1;
		}
		return 0;
	}
	for(i=o, temp=m-(n-1)*o; i<=temp; i++)
	{
		dp[n][m] += recursion(n-1, m-i);
	}
	return dp[n][m];
}

int main()
{
	int count, n, m, i, j, k;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d", &n, &m, &o);
		memset(dp, 0, sizeof(dp));
		printf("%d\n", recursion(n, m));
	}
	return 0;
}
