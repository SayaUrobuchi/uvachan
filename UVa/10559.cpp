#include <stdio.h>
#include <string.h>

short dp[200][200][200];
int tbl[201];
int c[201];
int ary[201];

int recursion(int left, int right, int len)
{
	int i, temp;
	if(dp[left][right][len])
	{
		return dp[left][right][len];
	}
	if(left == right)
	{
		/*printf("%d %d %d: %d\n", left, right, len, tbl[c[right]+len]);*/
		return dp[left][right][len]=tbl[c[right]+len];
	}
	dp[left][right][len] = recursion(left, right-1, 0) + tbl[c[right]+len];
	for(i=left; i<right-1; i++)
	{
		if(ary[i] == ary[right])
		{
			if((temp=recursion(left, i, c[right]+len)+recursion(i+1, right-1, 0)) > dp[left][right][len])
			{
				dp[left][right][len] = temp;
			}
		}
	}
	/*printf("%d %d %d: %d\n", left, right, len, dp[left][right][len]);*/
	return dp[left][right][len];
}

int main()
{
	int cas, count, n, m, i, buf;
	cas = 0;
	for(i=0; i<201; i++)
	{
		tbl[i] = i * i;
	}
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &ary[0]);
		c[0] = 1;
		for(i=1, m=0; i<n; i++)
		{
			scanf("%d", &buf);
			if(buf == ary[m])
			{
				c[m]++;
			}
			else
			{
				ary[++m] = buf;
				c[m] = 1;
			}
		}
		memset(dp, 0, sizeof(dp));
		printf("Case %d: %d\n", ++cas, recursion(0, m, 0));
	}
	return 0;
}
