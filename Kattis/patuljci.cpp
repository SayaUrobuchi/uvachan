#include <stdio.h>

int ary[16], path[16];

int dfs(int depth, int last, int sum)
{
	int i;
	if (depth == 7)
	{
		return sum == 100;
	}
	for (i=last; i<9; i++)
	{
		path[depth] = ary[i];
		if (sum+ary[i] <= 100 && dfs(depth+1, i+1, sum+ary[i]))
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	int i;
	for (i=0; i<9; i++)
	{
		scanf("%d", &ary[i]);
	}
	dfs(0, 0, 0);
	for (i=0; i<7; i++)
	{
		printf("%d\n", path[i]);
	}
	return 0;
}
