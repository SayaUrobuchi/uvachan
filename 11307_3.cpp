#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define COLOR 21

int num[10000];
int parent[10000];
int temp[10000];
int *ary[10000];
int dp[10001][COLOR];
int deg[10001];
char str[1000000];

void dfs(int now, int depth)
{
	int i;
	deg[depth]++;
	for(i=0; i<num[now]; i++)
	{
		dfs(ary[now][i], depth+1);
	}
	free(ary[now]);
}

int main()
{
	int n, i, j, k, root, child;
	char *ptr;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		gets(str);
		memset(parent, 0, sizeof(parent));
		for(i=0; i<n; i++)
		{
			gets(str);
			ptr = strtok(str, ":");
			sscanf(ptr, "%d", &root);
			num[root] = 0;
			while(ptr=strtok(NULL, " "))
			{
				sscanf(ptr, "%d", &child);
				temp[num[root]++] = child;
				parent[child] = 1;
			}
			ary[root] = (int*)malloc(sizeof(int)*num[root]);
			memcpy(ary[root], temp, sizeof(int)*num[root]);
		}
		for(i=0; i<n; i++)
		{
			if(!parent[i])
			{
				break;
			}
		}
		memset(deg, 0, sizeof(deg));
		dfs(i, 1);
		memset(dp, 0, sizeof(dp));
		for(i=1; i<=n; i++)
		{
			if(!deg[i])
			{
				break;
			}
			for(j=1; j<COLOR; j++)
			{
				for(k=1; k<COLOR; k++)
				{
					if(j != k)
					{
						if(!dp[i][j] || dp[i][j] > dp[i-1][k] + deg[i] * j)
						{
							dp[i][j] = dp[i-1][k] + deg[i] * j;
						}
					}
				}
			}
		}
		for(i--, j=1, k=0; j<COLOR; j++)
		{
			if(!k || k > dp[i][j])
			{
				k = dp[i][j];
			}
		}
		printf("%d\n", k);
	}
	return 0;
}
