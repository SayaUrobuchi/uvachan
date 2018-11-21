#include <stdio.h>
#include <string.h>

int ary[15], list[15], used[15], n, m;

int correct()
{
	int i, j;
	memcpy(ary, list, sizeof(ary));
	for(i=1; i<n; i++)
	{
		for(j=0; j<n-i; j++)
		{
			ary[j] += ary[j+1];
		}
	}
	if(ary[0] == m)
	{
		printf("%d", list[0]);
		for(i=1; i<n; i++)
		{
			printf(" %d", list[i]);
		}
		printf("\n");
		return 1;
	}
	return 0;
}

int dfs(int d)
{
	int i;
	if(d == n)
	{
		if(correct())
		{
			return 1;
		}
		return 0;
	}
	for(i=1; i<=n; i++)
	{
		if(used[i] == 0)
		{
			used[i] = 1;
			list[d] = i;
			if(dfs(d+1))
			{
				return 1;
			}
			used[i] = 0;
		}
	}
	return 0;
}

int main()
{
	while(scanf("%d%d", &n, &m) == 2)
	{
		memset(used, 0, sizeof(used));
		dfs(0);
	}
	return 0;
}
