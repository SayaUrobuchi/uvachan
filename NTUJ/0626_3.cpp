#include <stdio.h>

int ans, len;
char str[100005];

void dfs(int stat, int rem, int cost, int dep)
{
	int i, j, t;
	if(cost >= ans || dep >= len)
	{
		return;
	}
	if(stat == 0)
	{
		ans = cost;
		return;
	}
	if((stat & (1<<dep)) == 0)
	{
		dfs(stat, rem, cost, dep+1);
	}
	for(i=0; i<len; i++)
	{
		if(rem & (1<<i))
		{
			dfs((stat ^ (((1<<(i+1))-1)<<dep)), rem-(1<<i), cost+i+1, dep);
		}
	}
}

int main()
{
	int i, t;
	while(gets(str))
	{
		ans = 2147483647;
		for(i=0, t=0; str[i]; i++)
		{
			t += (str[i]=='1'?(1<<i):0);
		}
		len = i;
		if(len == 1 && str[0] == '0')
		{
			break;
		}
		dfs(t, (1<<len)-1, 0, 0);
		printf("%d\n", ans);
	}
	return 0;
}
