#include <stdio.h>
#include <string.h>

int len, m;
int used[10005], dp[1025][10005];
char buf[10005];

void calc(int bb)
{
	int i, j, tt, list[10];
	if(used[bb])
	{
		return;
	}
	used[bb] = 1;
	if(bb == 0)
	{
		dp[bb][0] = 1;
		return;
	}
	memset(list, 0, sizeof(list));
	for(i=0; i<len; i++)
	{
		if(list[buf[i]-'0'] == 0 && (bb & (1<<i)))
		{
			list[buf[i]-'0'] = 1;
			calc(tt=bb-(1<<i));
			for(j=0; j<m; j++)
			{
				dp[bb][(j*10+buf[i]-'0')%m] += dp[tt][j];
			}
		}
	}
}

int main()
{
	int count;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%s%d", buf, &m);
		len = strlen(buf);
		memset(used, 0, sizeof(used));
		memset(dp, 0, sizeof(dp));
		calc((1<<len)-1);
		printf("%d\n", dp[(1<<len)-1][0]);
	}
	return 0;
}
