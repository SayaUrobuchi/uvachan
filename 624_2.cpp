#include <stdio.h>
#include <string.h>

int ary[21];
int dp[2000];
char str[10001];

void backtracing(int now)
{
	if(now)
	{
		printf("%d ", dp[now]);
		backtracing(now-dp[now]);
	}
}

int main()
{
	int n, m, i, j;
	char *ptr;
	while(scanf("%d%d", &n, &m) == 2)
	{
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for(i=0; i<m; i++)
		{
			scanf("%d", &ary[i]);
			for(j=n; j>=ary[i]; j--)
			{
				if(!dp[j] && dp[j-ary[i]])
				{
					dp[j] = ary[i];
				}
			}
		}
		for(i=n; i>-1; i--)
		{
			if(dp[i])
			{
				break;
			}
		}
		backtracing(i);
		printf("sum:%d\n", i);
	}
	return 0;
}
