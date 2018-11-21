#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int p[1005], q[1005], idd[1005];
char s[1000005];
long long dp[1005][1005];

int comp(const void *pp, const void *qq)
{
	if(p[*(int*)pp] != p[*(int*)qq])
	{
		return p[*(int*)qq]-p[*(int*)pp];
	}
	return q[*(int*)pp]-q[*(int*)qq];
}

int main()
{
	int count, n, i, j, id, turn;
	long long ans;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%s", &n, s);
		turn = 2;
		if(*s == 'P')
		{
			turn = 1;
		}
		for(i=1; i<=n; i++)
		{
			scanf("%d%d", &p[i], &q[i]);
			q[i] *= 2000000;
			idd[i] = i;
		}
		qsort(idd+1, n, sizeof(int), comp);
		for(i=1; i<=n; i++, turn++)
		{
			id = idd[i];
			dp[i][0] = dp[i-1][0]+p[id];
			for(j=1; j<=(turn>>1); j++)
			{
				if(j > ((turn-1)>>1))
				{
					dp[i][j] = 0;
				}
				else
				{
					dp[i][j] = dp[i-1][j]+p[id];
				}
				if(dp[i-1][j-1]+q[id] > dp[i][j])
				{
					dp[i][j] = dp[i-1][j-1]+q[id];
				}
			}
		}
		turn--;
		ans = dp[n][turn>>1];
		printf("%d %d\n", (int)(ans%2000000), (int)(ans/2000000));
	}
	return 0;
}
