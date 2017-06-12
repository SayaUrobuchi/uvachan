#include <stdio.h>
#include <string.h>

int mincap[100], maxcap[100];
int dp[450000];

int main()
{
	int count, n, m, i, j, k, maxc, minc, rate;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for(i=0; i<m; i++)
		{
			scanf("%d%d", &mincap[i], &maxcap[i]);
		}
		n *= 1000;
		for(i=0; i<m; i++)
		{
			maxc = maxcap[i];
			minc = mincap[i];
			rate = minc * 100 / maxc + 1;
			if(n >= rate * maxcap[i])
			{
				break;
			}
			for(j=0; j+minc<=n; j++)
			{
				if(dp[j])
				{
					for(k=j+minc; k<=j+maxc; k++)
					{
						dp[k] = 1;
					}
				}
			}
		}
		if(i < m)
		{
			printf("0\n");
		}
		else
		{
			for(i=n, j=0; !dp[i]; i--, j++);
			printf("%d\n", j);
		}
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
