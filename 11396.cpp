#include <stdio.h>
#include <string.h>

int color[305];
int num[305];
int ary[305][3];

int dfs(int node, int c)
{
	int i;
	color[node] = c;
	c = 3 - c;
	for(i=0; i<3; i++)
	{
		if(!color[ary[node][i]])
		{
			if(dfs(ary[node][i], c))
			{
				return 1;
			}
		}
		else if(color[ary[node][i]] != c)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	int n, i, j, k, c, temp;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		memset(color, 0, sizeof(color));
		memset(num, 0, sizeof(num));
		while(scanf("%d%d", &i, &j) == 2)
		{
			if(!i && !j)
			{
				break;
			}
			ary[i][num[i]++] = j;
			ary[j][num[j]++] = i;
		}
		for(i=1; i<=n; i++)
		{
			if(!color[i])
			{
				if(dfs(i, 1))
				{
					break;
				}
			}
		}
		if(i > n)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
