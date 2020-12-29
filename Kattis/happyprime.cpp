#include <iostream>

const int UNKNOWN = 0;
const int WAITING = 1;
const int HAPPY = 2;
const int UNHAPPY = 3;

int dp[16384];

int is_h(int n)
{
	int res, t;
	if (n == 1)
	{
		return dp[n] = HAPPY;
	}
	if (dp[n] == WAITING)
	{
		return dp[n] = UNHAPPY;
	}
	if (dp[n] != UNKNOWN)
	{
		//printf("record %d return %d\n", n, dp[n]);
		return dp[n];
	}
	dp[n] = WAITING;
	//printf("%d", n);
	for (res=0, t=n; t; res+=(t%10)*(t%10), t/=10);
	//printf(" => %d\n", res);
	return dp[n] = is_h(res);
}

bool is_p(int n)
{
	int i;
	if (n == 1)
	{
		return false;
	}
	for (i=2; i*i<=n; i++)
	{
		if (n%i == 0)
		{
			return false;
		}
	}
	//printf("%d is prime.\n", n);
	return true;
}

int main()
{
	int count, cas, n;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &cas, &n);
		printf("%d %d %s\n", cas, n, is_p(n) && is_h(n) == HAPPY ? "YES" : "NO");
	}
	return 0;
}
