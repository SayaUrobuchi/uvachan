#include <iostream>
using namespace std;

bool used[105][105], dp[105][105];

bool recurs(int x, int y)
{
	int i;
	if (x > y)
	{
		swap(x, y);
	}
	if (used[x][y])
	{
		return dp[x][y];
	}
	used[x][y] = true;
	dp[x][y] = false;
	if (x != 1 || y != 1)
	{
		for (i=1; i+1<=x&&!dp[x][y]; i++)
		{
			if (!recurs(i, y) && !recurs(x-i, y))
			{
				dp[x][y] = true;
			}
		}
		for (i=1; i+1<=y&&!dp[x][y]; i++)
		{
			if (!recurs(x, i) && !recurs(x, y-i))
			{
				dp[x][y] = true;
			}
		}
	}
	return dp[x][y];
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	if (recurs(n, m))
	{
		puts("A");
	}
	else
	{
		puts("B");
	}
	return 0;
}