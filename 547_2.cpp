#include <stdio.h>
#include <math.h>

#define N 3000

int dp[N+1];
char buf[2008];

int getnum(int now)
{
	int res;
	for(res=0; now>0; res+=now%10, now/=10);
	return res;
}

int getres(int now)
{
	int i, s, sq, res;
	for(i=1, s=1+now%2, sq=(int)sqrt((double)now), res=0; i<=sq; i+=s)
	{
		if(!(now % i))
		{
			res += getnum(i);
			if(i*i != now)
			{
				res += getnum(now/i);
			}
		}
	}
	return res;
}

int recursion(int now)
{
	int res;
	if(dp[now])
	{
		return dp[now];
	}
	res = getres(now);
	if(res == now)
	{
		return dp[now]=1;
	}
	return dp[now]=recursion(res)+1;
}

void output(int now)
{
	int res;
	res = getres(now);
	printf(" %d", now);
	if(res != now)
	{
		output(res);
	}
}

int main()
{
	int cas, n, m, i, max, temp;
	cas = 0;
	for(i=1; i<=N; i++)
	{
		recursion(i);
	}
	while(scanf("%d%d", &n, &m) == 2)
	{
		printf("Input%d: %d %d\n", ++cas, n, m);
		if(n > m)
		{
			n ^= m ^= n ^= m;
		}
		for(i=n, max=0; i<=m; i++)
		{
			if(dp[i] > max)
			{
				max = dp[i];
				temp = i;
			}
		}
		printf("Output%d:", cas);
		output(temp);
		printf("\n");
	}
	return 0;
}
