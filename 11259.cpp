#include <stdio.h>
#include <string.h>

int num[4], value[4], dp[100001];

int main()
{
	int count, m, i, j, k, l, target;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d%d%d", &value[0], &value[1], &value[2], &value[3], &m);
		while(m--)
		{
			scanf("%d%d%d%d%d", &num[0], &num[1], &num[2], &num[3], &target);
			memset(dp, 0, sizeof(dp));
			dp[0] = 1;
			for(i=0; i<4; i++)
			{
				for(j=target; j>=value[i]; j--)
				{
					for(k=0, l=j-value[i]; k<num[i]&&l>=0; k++, l-=value[i])
					{
						dp[j] += dp[l];
					}
				}
			}
			printf("%d\n", dp[target]);
		}
	}
	return 0;
}
