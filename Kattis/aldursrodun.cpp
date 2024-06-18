#include <iostream>
using namespace std;

const int N = 15;

int n;
int ary[N], path[N];
bool used[N];

int gcd(int a, int b)
{
	while ((a %= b) && (b %= a));
	return a + b;
}

bool dfs(int depth)
{
	int i;
	if (depth == n)
	{
		return true;
	}
	for (i=0; i<n; i++)
	{
		if (!used[i] && (!depth || gcd(ary[i], path[depth-1]) > 1))
		{
			used[i] = true;
			path[depth] = ary[i];
			if (dfs(depth+1))
			{
				return true;
			}
			used[i] = false;
		}
	}
	return false;
}

int main()
{
	int i;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	if (dfs(0))
	{
		printf("%d", path[0]);
		for (i=1; i<n; i++)
		{
			printf(" %d", path[i]);
		}
		puts("");
	}
	else
	{
		puts("Neibb");
	}
	return 0;
}
