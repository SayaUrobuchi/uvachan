#include <stdio.h>

int ans, len, end;
char str[100005];

void dfs(int stat, int last, int cost)
{
	int i, j, t;
	if(stat == 0 && cost <= ans)
	{
		end = 1;
		return;
	}
	if(cost >= ans || last > len)
	{
		return;
	}
	for(i=last; i<=len; i++)
	{
		for(j=len-i-1; j>=0; j--)
		{
			t = (stat ^ (((1<<i)-1)<<j));
			dfs(t, i+1, cost+i);
			if(end)
			{
				return;
			}
		}
	}
	dfs(stat, last+1, cost);
}

int main()
{
	int i, t;
	while(gets(str))
	{
		ans = 2147483647;
		end = 0;
		for(i=0, t=0; str[i]; i++)
		{
			t += (str[i]=='1'?(1<<i):0);
		}
		len = i;
		if(len == 1 && str[0] == '0')
		{
			break;
		}
		for(ans=0; ; ans++)
		{
			dfs(t, 1, 0);
			if(end)
			{
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
