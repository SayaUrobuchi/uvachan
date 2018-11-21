#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int used[205];
int num[205];
int list[205][205];
int index[42000];
int rx[42000], ry[42000];

int comp(const void *p, const void *q)
{
	if(rx[*(int*)p] == rx[*(int*)q])
	{
		return ry[*(int*)p] - ry[*(int*)q];
	}
	return rx[*(int*)p] - rx[*(int*)q];
}

int dfs(int now, int target)
{
	int i;
	if(now == target)
	{
		return 1;
	}
	for(i=0; i<num[now]; i++)
	{
		if(!used[list[now][i]])
		{
			used[list[now][i]] = 1;
			if(dfs(list[now][i], target))
			{
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int n, m, i, j, k, curr;
	while(scanf("%d", &n) == 1)
	{
		memset(num, 0, sizeof(num));
		for(i=0; i<n; i++)
		{
			scanf("%d (%d)", &curr, &m);
			num[curr] = m;
			while(m--)
			{
				scanf("%d", &list[curr][m]);
			}
		}
		for(i=0, k=0; i<n; i++)
		{
			for(j=0; j<num[i]; j++)
			{
				if(list[i][j] > i)
				{
					curr = list[i][j];
					list[i][j] = i;
					memset(used, 0, sizeof(used));
					used[i] = 1;
					if(!dfs(i, curr))
					{
						index[k] = k;
						rx[k] = i;
						ry[k++] = curr;
					}
					list[i][j] = curr;
				}
			}
		}
		printf("%d critical links\n", k);
		qsort(index, k, sizeof(int), comp);
		for(i=0; i<k; i++)
		{
			printf("%d - %d\n", rx[index[i]], ry[index[i]]);
		}
		printf("\n");
	}
	return 0;
}
