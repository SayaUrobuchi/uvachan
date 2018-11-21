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
		return 1;
	}
	if(depth == lim)
	{
		return 0;
	}
	for(j=depth-1; j>-1; j--)
	{
		if(!chk[j] && list[depth-1] + list[j] <= n)
		{
			if(j != depth-1)
			{
				chk[j] = 1;
			}
			list[depth] = list[depth-1] + list[j];
			if(dfs(depth+1))
			{
				return 1;
			}
			chk[j] = 0;
		}
	}
	return 0;
}

int main()
{
	int i, temp;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		for(i=n, lim=0, temp=0; i; i/=2)
		{
			lim++;
			temp += i % 2;
		}
		lim += temp / 2 - 1;
		list[0] = 1;
		for(; ; lim++)
		{
			printf("%d\n", lim);
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
