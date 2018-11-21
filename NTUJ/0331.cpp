#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, tbl[128];
char used[200], list[200], s[200];

int comp(const void *p, const void *q)
{
	return tbl[*(char*)p] - tbl[*(char*)q];
}

void dfs(int depth)
{
	int i;
	if(depth == n)
	{
		list[depth] = 0;
		printf("%s\n", list);
		return;
	}
	for(i=0; i<n; i++)
	{
		if(used[i] == 0 && (i == 0 || (used[i-1] || s[i-1] != s[i])))
		{
			used[i] = 1;
			list[depth] = s[i];
			dfs(depth+1);
			used[i] = 0;
		}
	}
}

int main()
{
	int count, i;
	for(i=0; i<26; i++)
	{
		tbl[65+i] = i*2;
		tbl[97+i] = i*2+1;
	}
	scanf("%d", &count);
	gets(s);
	while(count--)
	{
		gets(s);
		n = strlen(s);
		qsort(s, n, sizeof(char), comp);
		memset(used, 0, sizeof(used));
		dfs(0);
	}
	return 0;
}
