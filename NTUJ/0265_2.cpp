#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int id[100];
int rate[100];
int mincap[100], maxcap[100];
int dp[450000], list[450000];

int comp(const void *p, const void *q)
{
	return rate[*(int*)p] - rate[*(int*)q];
}

int main()
{
	int n, m, i, j, k, p, q, now, maxc, minc;
	while(scanf("%d%d", &n, &m) == 2)
	{
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for(i=0; i<m; i++)
		{
			scanf("%d%d", &mincap[i], &maxcap[i]);
			rate[i] = mincap[i] * 100 / maxcap[i] + 1;
			rate[i] *= maxcap[id[i]];
			id[i] = i;
		}
		qsort(id, m, sizeof(int), comp);
		n *= 1000;
		if(n >= rate[id[i]])
		{
			printf("0\n");
		}
		else
		{
			for(i=1; i<n; i++)
			{
				list[i-1] = i;
			}
			for(i=0, p=n-1; i<m; i++)
			{
				maxc = maxcap[id[i]];
				minc = mincap[id[i]];
				for(j=0, q=0; j<p; j++)
				{
					now = list[j];
					if(now >= minc)
					{
						for(k=minc; k<=maxc&&now-k>=0; k++)
						{
							if(dp[now-k])
							{
								dp[now] = 1;
								break;
							}
						}
						if(dp[now] == 0)
						{
							list[q++] = now;
						}
					}
				}
				if(dp[n])
				{
					break;
				}
				p = q;
			}
			for(i=n, j=0; !dp[i]; i--, j++);
			printf("%d\n", j);
		}
	}
	return 0;
}
