#include <stdio.h>
#include <string.h>

int n, used[200000][18], dp[200000][18], tbl[200000], ary[20];

int abs(int number)
{
	return number < 0 ? -number : number;
}

int max(int p, int q)
{
	return p > q ? p : q;
}

int recursion(int state, int loc, int depth)
{
	int i, temp, time;
	if(used[state][loc] == 1)
	{
		return dp[state][loc];
	}
	used[state][loc] = 1;
	if(state == 0)
	{
		return dp[state][loc]=ary[loc] * ((loc-1)/ary[loc]+1);
	}
	for(i=1, temp=2147483647; i<=n; i++)
	{
		if(state & (1<<i))
		{
			time = recursion(state-(1<<i), i, depth-1) + abs(i-loc);
			time = ary[loc] * ((time-1)/ary[loc]+1);
			if(time < temp)
			{
				temp = time;
			}
		}
	}
	return dp[state][loc]=temp;
}

int main()
{
	int i, ans;
	for(i=0; i<18; i++)
	{
		tbl[1<<i] = i;
	}
	while(scanf("%d", &n) == 1)
	{
		for(i=1; i<=n; i++)
		{
			scanf("%d", &ary[i]);
		}
		memset(used, 0, sizeof(used));
		for(i=1, ans=2147483647; i<=n; i++)
		{
			if(recursion((2<<n)-2-(1<<i), i, n) < ans)
			{
				ans = dp[(2<<n)-2-(1<<i)][i];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
