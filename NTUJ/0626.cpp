#include <stdio.h>

int ans, len;
char str[100005];

void dfs(int stat, int last, int cost)
{
	int i, j, t;
	if(cost >= ans || last > len)
	{
		return;
	}
	if(stat == 0)
	{
		ans = cost;
		return;
	}
	for(i=last; i<=len; i++)
	{
		for(j=len-i-1; j>=0; j--)
		{
			if((j && (stat & (1<<(j-1))) || (stat & (1<<(j+i)))) || (stat & (((1<<i)-1)<<j)))
			{
				t = (stat ^ (((1<<i)-1)<<j));
				dfs(t, i+1, cost+i);
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
		for(i=0, t=0; str[i]; i++)
		{
			t += (str[i]=='1'?(1<<i):0);
		}
		len = i;
		if(len == 1 && str[0] == '0')
		{
			break;
		}
		dfs(t, 1, 0);
		printf("%d\n", ans);
	}
	return 0;
}
