#include <stdio.h>
#include <string.h>
#include <math.h>

int n, lim;
int list[100], chk[100];

int dfs(int depth)
{
	int i, j, temp;
	if(list[depth-1] == n)
	{
		lim = depth;
		return 1;
	}
	if(depth == lim)
	{
		return 0;
	}
	for(i=depth-1; /*i>-1*/i>depth-2; i--)
	{
		for(j=i; j>-1; j--)
		{
			if(!chk[i] && list[i] + list[j] <= n)
			{
				chk[i] = 1;
				list[depth] = list[i] + list[j];
				if(dfs(depth+1))
				{
					return 1;
				}
				chk[i] = 0;
			}
		}
	}
	return 0;
}

int main()
{
	int i;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		for(i=n, lim=-2; i; i/=2)
		{
			lim += i % 2 + 1;
		}
		list[0] = 1;
		for(; ; lim++)
		{
			memset(chk, 0, sizeof(chk));
			if(dfs(1))
			{
				break;
			}
		}
		printf("1");
		for(i=1; i<lim; i++)
		{
			printf(" %d", list[i]);
		}
		printf("\n");
	}
	return 0;
}
