#include <stdio.h>

int n, m, list[1000001][9], num[1000001], prime[1000001];
long long final;

void dfs(int* ary, int depth, int value, int num, int lim)
{
	if(depth == lim)
	{
		if(value != 1)
		{
			if(num)
			{
				final -= m / value;
			}
			else
			{
				final += m / value;
			}
		}
		return;
	}
	dfs(ary, depth+1, value, num, lim);
	dfs(ary, depth+1, value*ary[depth], 1-num, lim);
}

int main()
{
	int i, j;
	for(i=2; i<=1000000; i+=2)
	{
		list[i][num[i]++] = 2;
	}
	for(i=3; i<=1000000; i+=2)
	{
		if(prime[i] == 0)
		{
			for(j=i; j<=1000000; j+=i)
			{
				list[j][num[j]++] = i;
				prime[j] = 1;
			}
		}
	}
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n > m)
		{
			i = n;
			n = m;
			m = i;
		}
		for(i=2, final=0; i<=n; i++)
		{
			dfs(list[i], 0, 1, 0, num[i]);
		}
		printf("%lld\n", (long long)n*(long long)m+final);
	}
	return 0;
}
