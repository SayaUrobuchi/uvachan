#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define COLOR 11

int num[10000];
int parent[10000];
int temp[10000];
int *ary[10000];
int dp[10001][COLOR];
int deg[10001];
char str[1000000];

void dfs(int now, int depth)
{
	int i, j, k, min, temp;
	for(i=1; i<COLOR; i++)
	{
		dp[now][i] = i;
	}
	for(i=0; i<num[now]; i++)
	{
		dfs(temp=ary[now][i], depth+1);
		for(j=1; j<COLOR; j++)
		{
			for(k=1, min=1073741824; k<COLOR; k++)
			{
				if(j != k)
				{
					if(dp[temp][k] < min)
					{
						min = dp[temp][k];
					}
				}
			}
			dp[now][j] += min;
		}
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
		dfs(i, 1);
		for(j=1, k=1073741824; j<COLOR; j++)
		{
			if(dp[i][j] < k)
			{
				k = dp[i][j];
			}
		}
		printf("%d\n", k);
	}
	return 0;
}
