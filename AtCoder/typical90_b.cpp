#include <iostream>
using namespace std;

int n;
char path[32];

void dfs(int depth, int top)
{
	if (depth == n)
	{
		puts(path);
		return;
	}
	if (depth + (top+2) <= n)
	{
		path[depth] = '(';
		dfs(depth+1, top+1);
	}
	if (top)
	{
		path[depth] = ')';
		dfs(depth+1, top-1);
	}
}

int main()
{
	while (scanf("%d", &n) == 1)
	{
		if (!(n & 1))
		{
			path[n] = 0;
			dfs(0, 0);
		}
	}
	return 0;
}
