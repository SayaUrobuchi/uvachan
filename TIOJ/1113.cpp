#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int l;
char used[10], str[10], list[10];

int comp(const void *p, const void *q)
{
	return *(char*)p - *(char*)q;
}

void dfs(int depth)
{
	int i;
	if(depth == l)
	{
		puts(list);
	}
	for(i=0; i<l; i++)
	{
		if(used[i] == 0)
		{
			list[depth] = str[i];
			used[i] = 1;
			dfs(depth+1);
			used[i] = 0;
		}
	}
}

int main()
{
	int cas;
	cas = 0;
	while(scanf("%s", str) == 1)
	{
		qsort(str, l=strlen(str), sizeof(char), comp);
		if(cas++)
		{
			printf("\n");
		}
		dfs(list[l]=0);
	}
	return 0;
}
