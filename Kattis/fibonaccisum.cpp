#include <iostream>
using namespace std;

const int N = 43;

int dp[N];
bool first;

void recurs(int n, int d)
{
	if (n == 0)
	{
		return;
	}
	if (n >= dp[d])
	{
		recurs(n-dp[d], d-1);
		if (!first)
		{
			putchar(' ');
		}
		printf("%d", dp[d]);
		first = false;
	}
	else
	{
		recurs(n, d-1);
	}
}

int main()
{
	int n, i;
	dp[0] = 1;
	dp[1] = 2;
	for (i=2; i<N; i++)
	{
		dp[i] = dp[i-1] + dp[i-2];
		//printf("%d: %d\n", i, dp[i]);
	}
	scanf("%d", &n);
	first = true;
	recurs(n, N-1);
	puts("");
	return 0;
}
