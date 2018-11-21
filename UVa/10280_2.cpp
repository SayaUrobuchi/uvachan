#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int index[100];
int rate[100];
int mincap[100], maxcap[100];
int dp[450000];

int comp(const void *p, const void *q)
{
	return rate[*(int*)p] - rate[*(int*)q];
}

int main()
{
	int count, n, m, i, j, k, maxc, minc;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for(i=0; i<m; i++)
		{
			scanf("%d%d", &mincap[i], &maxcap[i]);
			rate[i] = mincap[i] * 100 / maxcap[i] + 1;
			rate[i] *= maxcap[index[i]];
			index[i] = i;
		}
		qsort(index, m, sizeof(int), comp);
		n *= 1000;
		if(n >= rate[index[i]])
		{
			printf("0\n");
		}
		else
		{
			for(i=0; i<m; i++)
			{
				maxc = maxcap[index[i]];
				minc = mincap[index[i]];
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
				if(dp[n])
				{
					break;
				}
			}
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
