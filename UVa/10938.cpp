#include <stdio.h>
#include <string.h>

int used[5005], list[5005], map[5005][501], num[5005];

int min(int p, int q)
{
	return p<q ? p : q;
}

int max(int p, int q)
{
	return p>q ? p : q;
}

int dfs(int depth, int now, int target)
{
	int i;
	used[now] = 1;
	list[depth] = now;
	if(now == target)
	{
		if(depth % 2)
		{
			printf("The fleas jump forever between %d and %d.\n", min(list[depth/2], list[depth/2+1]), max(list[depth/2], list[depth/2+1]));
		}
		else
		{
			printf("The fleas meet at %d.\n", list[depth/2]);
		}
		return 1;
	}
	for(i=0; i<num[now]; i++)
	{
		if(used[map[now][i]] == 0)
		{
			if(dfs(depth+1, map[now][i], target))
			{
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int n, i, p, q;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		memset(num, 0, sizeof(num));
		for(i=1; i<n; i++)
		{
			scanf("%d%d", &p, &q);
			map[p][num[p]++] = q;
			map[q][num[q]++] = p;
		}
		scanf("%d", &n);
		while(n--)
		{
			memset(used, 0, sizeof(used));
			scanf("%d%d", &p, &q);
			dfs(0, p, q);
		}
	}
	return 0;
}
