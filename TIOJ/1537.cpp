#include <stdio.h>

int lis[26];

void dfs(int rem, int las, int dep)
{
	int i;
	if(rem == 0)
	{
		if(dep > 1)
		{
			printf("%d", lis[0]);
			for(i=1; i<dep; i++)
			{
				printf(", %d", lis[i]);
			}
			printf("\n");
		}
		return;
	}
	if(rem < las)
	{
		return;
	}
	for(i=las; i<=rem; i++)
	{
		lis[dep] = i;
		dfs(rem-i, i, dep+1);
	}
}

int main()
{
	int cas, count, n;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		printf("Plank %d:\n", ++cas);
		dfs(n, 1, 0);
	}
	return 0;
}
