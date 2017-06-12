#include <stdio.h>
#include <string.h>

int black, white;
int num[10000];
int ary[10000][1000];
int parent[10000];
char str[100000];

void dfs(int now, int type)
{
	int i;
	if(type)
	{
		white++;
	}
	else
	{
		black++;
	}
	type = 1 - type;
	for(i=0; i<num[now]; i++)
	{
		dfs(ary[now][i], type);
	}
}

int main()
{
	int n, i, root, child;
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
				if(num[root] >= 1000) while(1);
				ary[root][num[root]++] = child;
				parent[child] = 1;
			}
		}
		for(i=0; i<n; i++)
		{
			if(!parent[i])
			{
				break;
			}
		}
		black = white = 0;
		dfs(i, 0);
		if(black > white)
		{
			printf("%d\n", black+white+white);
		}
		else
		{
			printf("%d\n", black+black+white);
		}
	}
	return 0;
}
