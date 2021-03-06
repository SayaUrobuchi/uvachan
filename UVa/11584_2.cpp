#include <stdio.h>
#include <string.h>

int dp[1024], tbl[1024][1024], map[1024][1024], mnum[1024];
char buf[1024];

int main()
{
	int cnt, i, j, n;
	scanf("%d", &cnt);
	while(cnt--)
	{
		scanf("%s", buf);
		memset(tbl, 0, sizeof(tbl));
		memset(mnum, 0, sizeof(mnum));
		n = strlen(buf);
		for(i=0; i<n; i++)
		{
			tbl[i][i] = 1;
			map[i][mnum[i]++] = i;
			if(i)
			{
				tbl[i][i-1] = 1;
			}
		}
		for(i=1; i<n; i++)
		{
			for(j=0; j+i<n; j++)
			{
				if(buf[j] == buf[j+i])
				{
					tbl[j][j+i] = tbl[j+1][j+i-1];
					if(tbl[j][j+i])
					{
						map[j+i][mnum[j+i]++] = j;
					}
				}
			}
		}
		for(i=0; i<n; i++)
		{
			if(tbl[0][i])
			{
				dp[i] = 1;
				continue;
			}
			dp[i] = n;
			for(j=0; j<mnum[i]; j++)
			{
				if(dp[i] > dp[map[i][j]-1] + 1)
				{
					dp[i] = dp[map[i][j]-1] + 1;
				}
			}
		}
		printf("%d\n", dp[n-1]);
	}
	return 0;
}
