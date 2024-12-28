/*
	ID: sa072682
	LANG: C
	TASK: pprime
*/
#include <stdio.h>
#include <math.h>

int ans[100000], dp[10], list[10], prime[3000], c, cp;
char tbl[11000];

int bisearch(int target)
{
	int left, right, center;
	left = 0;
	right = c - 1;
	while(1)
	{
		center = left + right;
		center /= 2;
		if(ans[center] == target)
		{
			return center;
		}
		else if(ans[center] > target)
		{
			right = center - 1;
			if(left > right)
			{
				return center;
			}
		}
		else
		{
			left = center + 1;
			if(left > right)
			{
				return center + 1;
			}
		}
	}
}

char isprime(int n)
{
	int i;
	for(i=0; prime[i]*prime[i]<=n; i++)
	{
		if(!(n % prime[i]))
		{
			return 0;
		}
	}
	return 1;
}

void dfs(int len, int length, int type, int depth, int value)
{
	int i;
	if(depth == length)
	{
		for(i=depth+type; i<len; i++)
		{
			value += list[len-i-1] * dp[i];
		}
		if(type)
		{
			for(i=0; i<10; i++, value+=dp[depth])
			{
				if(isprime(value))
				{
					ans[c++] = value;
				}
			}
		}
		else
		{
			if(isprime(value))
			{
				ans[c++] = value;
			}
		}
		return;
	}
	for(i=0; i<10; i++, value+=dp[depth])
	{
		list[depth] = i;
		dfs(len, length, type, depth+1, value);
	}
}

int main()
{
	int n, m, i;
	freopen("pprime.in", "r", stdin);
	freopen("pprime.out", "w", stdout);
	dp[0] = 1;
	for(i=1; i<10; i++)
	{
		dp[i] = dp[i-1] * 10;
	}
	for(i=3, cp=0; i<120; i+=2)
	{
		if(!tbl[i])
		{
			prime[cp++] = i;
			n = i + i;
			for(m=i*i; m<11000; m+=n)
			{
				tbl[m] = 1;
			}
		}
	}
	for(; i<11000; i+=2)
	{
		if(!tbl[i])
		{
			prime[cp++] = i;
		}
	}
	ans[0] = 2;
	ans[1] = 3;
	ans[2] = 5;
	ans[3] = 7;
	for(i=2, c=4; i<9; i++)
	{
		list[0] = 1;
		dfs(i, i/2, i%2, 1, 1);
		list[0] = 3;
		dfs(i, i/2, i%2, 1, 3);
		list[0] = 7;
		dfs(i, i/2, i%2, 1, 7);
		list[0] = 9;
		dfs(i, i/2, i%2, 1, 9);
	}
	scanf("%d%d", &n, &m);
	i = bisearch(n);
	for(; ans[i]<=m&&i<c; i++)
	{
		printf("%d\n", ans[i]);
	}
	scanf(" ");
	return 0;
}
