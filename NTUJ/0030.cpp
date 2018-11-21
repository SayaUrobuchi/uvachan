#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char ary[100005][11], *s[100005];

int comp(const void *p, const void *q)
{
	return strcmp(*(char**)p, *(char**)q);
}

int main()
{
	int n, i;
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			scanf("%s", s[i]=ary[i]);
		}
		qsort(s, n, sizeof(char*), comp);
		printf("%s", s[0]);
		for(i=1; i<n; i++)
		{
			printf("->%s", s[i]);
		}
		printf("\n");
	}
	return 0;
}
