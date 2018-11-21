#include <stdio.h>
#include <string.h>

int n, m;
int ex, ey;
int chk[15];
int x[15], y[15];

int dfs(int start, int depth)
{
	int i;
	if(depth == n)
	{
		if(start == ex)
		{
			printf("YES\n");
			return 1;
		}
		return 0;
	}
	for(i=0; i<m; i++)
	{
		if(!chk[i])
		{
			chk[i] = 1;
			if(x[i] == start)
			{
				if(dfs(y[i], depth+1))
				{
					return 1;
				}
			}
			else if(y[i] == start)
			{
				if(dfs(x[i], depth+1))
				{
					return 1;
				}
			}
			chk[i] = 0;
		}
	}
	return 0;
}

int main()
{
	int i, ix, iy;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		scanf("%d%d%d%d%d", &m, &ix, &iy, &ex, &ey);
		for(i=0; i<m; i++)
		{
			scanf("%d%d", &x[i], &y[i]);
		}
		memset(chk, 0, sizeof(chk));
		if(!dfs(iy, 0))
		{
			printf("NO\n");
		}
	}
	return 0;
}
