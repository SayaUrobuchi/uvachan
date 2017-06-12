#include <stdio.h>
#include <string.h>

int dfs[1000], bfs[1000], loc[1000], parent[1000], child[1000][1001];
char check[1000];

int main()
{
	int n, i, j, now, last, lnum;
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			scanf("%d", &bfs[i]);
		}
		for(i=0; i<n; i++)
		{
			scanf("%d", &dfs[i]);
			loc[dfs[i]] = i;
		}
		memset(check, 0, sizeof(check));
		memset(child, 0, sizeof(child));
		for(i=0, last=0, lnum=bfs[0]; i<n; i++)
		{
			child[i][0] = 1;
			now = bfs[i];
			j = loc[now];
			check[j] = 1;
			if(last >= j)
			{
				for(last++; last<n; last++)
				{
					if(check[last]) break;
					parent[last] = lnum;
				}
				last = j;
			}
			else
			{
				for(last++; last<j; last++)
				{
					if(check[last]) break;
					parent[last] = lnum;
				}
				last = j;
			}
			lnum = now;
		}
		for(i=1; i<n; i++)
		{
			child[parent[i]-1][child[parent[i]-1][0]++] = dfs[i];
		}
		for(i=0; i<n; i++)
		{
			printf("%d:", i+1);
			for(j=1; j<child[i][0]; j++)
			{
				printf(" %d", child[i][j]);
			}
			printf("\n");
		}
	}
    return 0;
}
