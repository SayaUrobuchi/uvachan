#include <iostream>
using namespace std;

bool used[505][505];
int dp[505][505];

int rec(int a, int b)
{
	int i;
	if (a > b)
	{
		swap(a, b);
	}
	if (used[a][b])
	{
		return dp[a][b];
	}
	used[a][b] = true;
	if (a == b)
	{
		return dp[a][b] = 0;
	}
	dp[a][b] = 1e9;
	for (i=1; i<=b-i; i++)
	{
		dp[a][b] = min(dp[a][b], rec(a, i)+rec(a, b-i)+1);
	}
	for (i=1; i<=a-i; i++)
	{
		dp[a][b] = min(dp[a][b], rec(i, b)+rec(a-i, b)+1);
	}
	return dp[a][b];
}

int main()
{
	int a, b;
	while (scanf("%d%d", &a, &b) == 2)
	{
		printf("%d\n", rec(a, b));
	}
	return 0;
}

