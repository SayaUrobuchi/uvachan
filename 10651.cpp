#include <stdio.h>

int dp[12], ans[4096], ary[12];

int min(int p, int q)
{
	if(p < q)
	{
		return p;
	}
	return q;
}

int recursion(int now, int num)
{
	int i, temp;
	if(ans[now])
	{
		return ans[now];
	}
	for(i=2, temp=num; i<12; i++)
	{
		if(ary[i] && ary[i-1] && !ary[i-2])
		{
			ary[i] = 1 - ary[i];
			ary[i-1] = 1 - ary[i-1];
			ary[i-2] = 1 - ary[i-2];
			temp = min(temp, recursion(now-dp[i]-dp[i-1]+dp[i-2], num-1));
			ary[i] = 1 - ary[i];
			ary[i-1] = 1 - ary[i-1];
			ary[i-2] = 1 - ary[i-2];
		}
	}
	for(i=0; i<10; i++)
	{
		if(ary[i] && ary[i+1] && !ary[i+2])
		{
			ary[i] = 1 - ary[i];
			ary[i-1] = 1 - ary[i-1];
			ary[i-2] = 1 - ary[i-2];
			temp = min(temp, recursion(now-dp[i]-dp[i+1]+dp[i+2], num-1));
			ary[i] = 1 - ary[i];
			ary[i-1] = 1 - ary[i-1];
			ary[i-2] = 1 - ary[i-2];
		}
	}
	return ans[now] = temp;
}

void dfs(int now, int depth, int num)
{
	if(depth == 12)
	{
		ans[now] = recursion(now, num);
		return;
	}
	ary[depth] = 0;
	dfs(now, depth+1, num);
	ary[depth] = 1;
	dfs(now+dp[depth], depth+1, num+1);
}

int main()
{
	int count, n, i;
	char buf[100];
	dp[0] = 1;
	for(i=1; i<12; i++)
	{
		dp[i] = dp[i-1] * 2;
	}
	dfs(0, 0, 0);
	scanf("%d", &count);
	gets(buf);
	while(count--)
	{
		gets(buf);
		for(i=0, n=0; i<12; i++)
		{
			if(buf[i] == 'o')
			{
				n += dp[i];
			}
		}
		printf("%d\n", ans[n]);
	}
	return 0;
}
