#include <stdio.h>

int n, k, value[100][100];
char map[100][100];

int dfs(int x, int y)
{
	int i, xtmp, ytmp, tmp, max;
	if(value[x][y] != -1)
	{
		return value[x][y];
	}
	max = 0;
	xtmp = x;
	ytmp = y;
	for(i=0; i<k; i++)
	{
		xtmp++;
		if(xtmp < n)
		{
			if(map[xtmp][ytmp] > map[x][y])
			{
				tmp = dfs(xtmp, ytmp);
				if(tmp > max)
				{
					max = tmp;
				}
			}
		}
		else
		{
			break;
		}
	}
	xtmp = x;
	ytmp = y;
	for(i=0; i<k; i++)
	{
		xtmp--;
		if(xtmp > -1)
		{
			if(map[xtmp][ytmp] > map[x][y])
			{
				tmp = dfs(xtmp, ytmp);
				if(tmp > max)
				{
					max = tmp;
				}
			}
		}
		else
		{
			break;
		}
	}
	xtmp = x;
	ytmp = y;
	for(i=0; i<k; i++)
	{
		ytmp++;
		if(ytmp < n)
		{
			if(map[xtmp][ytmp] > map[x][y])
			{
				tmp = dfs(xtmp, ytmp);
				if(tmp > max)
				{
					max = tmp;
				}
			}
		}
		else
		{
			break;
		}
	}
	xtmp = x;
	ytmp = y;
	for(i=0; i<k; i++)
	{
		ytmp--;
		if(ytmp > -1)
		{
			if(map[xtmp][ytmp] > map[x][y])
			{
				tmp = dfs(xtmp, ytmp);
				if(tmp > max)
				{
					max = tmp;
				}
			}
		}
		else
		{
			break;
		}
	}
	value[x][y] = max += map[x][y];
	return max;
}

int main()
{
	int count, i, j, in;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &k);
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				scanf("%d", &in);
				map[i][j] = in;
				value[i][j] = -1;
			}
		}
		printf("%d\n", dfs(0, 0));
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}