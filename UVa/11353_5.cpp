#include <stdio.h>

int *ptr, *ptr2;
int dp[2000002];
int tbl[21][500000];
int num[21];
int ary[2000002];

int main()
{
	int cas, n, i, j, k, sq;
	cas = 0;
	for(i=3; i<1415; i+=2)
	{
		if(!dp[i])
		{
			for(k=i*i, j=i+i; k<2000000; k+=j)
			{
				if(!dp[k])
				{
					dp[k] = k / i;
				}
			}
		}
	}
	tbl[0][num[0]++] = 1;
	for(i=2; i<2000000; i++)
	{
		j = dp[i] = dp[i>>1] + 1;
		tbl[j][num[j]++] = i;
		i++;
		j = dp[i] = dp[dp[i]] + 1;
		tbl[j][num[j]++] = i;
	}
	j = dp[i] = dp[i>>1] + 1;
	tbl[j][num[j]++] = i;
	for(i=0, ptr2=ary; i<21; i++)
	{
		ptr = tbl[i];
		sq = num[i];
		for(j=0; j<sq; j++)
		{
			*(++ptr2) = ptr[j];
		}
	}
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
