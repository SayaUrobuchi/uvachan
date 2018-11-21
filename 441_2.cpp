#include <stdio.h>

int n;
int res[8], ary[16];

void dfs(int depth, int start)
{
	int i;
	if (depth == 6)
	{
		printf("%d", res[0]);
		for (i=1; i<depth; i++)
		{
			printf(" %d", res[i]);
		}
		puts("");
		return;
	}
	if (n-start < 6-depth)
	{
		return;
	}
	for (i=start; i<n; i++)
	{
		res[depth] = ary[i];
		dfs(depth+1, i+1);
	}
}

int main()
{
	int i, cnt;
	cnt = 0;
	while (scanf("%d", &n) == 1)
	{
		if (!n)
		{
			break;
		}
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		if (cnt)
		{
			puts("");
		}
		++cnt;
		dfs(0, 0);
	}
	return 0;
}
