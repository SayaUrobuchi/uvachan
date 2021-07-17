#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char buf[100005*10005];
char *str[100005];

int comp(const void *a, const void *b)
{
	char *p, *q;
	p = *(char**)a;
	q = *(char**)b;
	return strcmp(p, q);
}

int main()
{
	int n, i;
	char *p;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, p=buf; i<n; i++)
		{
			scanf("%s", p);
			str[i] = p;
			p += strlen(p)+1;
		}
		qsort(str, n, sizeof(str[0]), comp);
		for (i=0; i<n; i++)
		{
			puts(str[i]);
		}
	}
	return 0;
}
