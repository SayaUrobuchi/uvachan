#include <stdio.h>
#include <string.h>

long long dp[51];
int ary[51][51], num[51];
int person[51];
long long tbl[10001];
long long unique[10001];

int main()
{
	int cas, count, n, m, i, j, sum;
	dp[0] = 1;
	for(i=1; i<51; i++)
	{
		dp[i] = dp[i-1] + dp[i-1];
	}
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		memset(tbl, 0, sizeof(tbl));
		for(i=0; i<n; i++)
		{
			scanf("%d", &num[i]);
			for(j=0; j<num[i]; j++)
			{
				scanf("%d", &ary[i][j]);
				tbl[ary[i][j]] |= dp[i];
				unique[ary[i][j]] = (tbl[ary[i][j]] ^ dp[i]);
			}
		}
		for(i=0, sum=0; i<n; i++)
		{
			for(j=0, person[i]=0; j<num[i]; j++)
			{
				if(!unique[ary[i][j]])
				{
					person[i]++;
					unique[ary[i][j]] = 1;
				}
			}
			sum += person[i];
		}
		printf("Case %d:", ++cas);
		for(i=0; i<n; i++)
		{
			printf(" %.6lf%%", 100.0*person[i]/sum);
		}
		printf("\n");
	}
	return 0;
}
