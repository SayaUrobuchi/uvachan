#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int index[10005];
char ary[10005][100];

int comp(const void *p, const void *q)
{
	return strcmp(ary[*(int*)p], ary[*(int*)q]);
}

int main()
{
	int count, n, i, j, p, q;
	char *ptr1, *ptr2;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%s", ary[i]);
			index[i] = i;
		}
		qsort(index, n, sizeof(int), comp);
		for(i=1; i<n; i++)
		{
			p = index[i-1];
			q = index[i];
			if(!strncmp(ary[p], ary[q], strlen(ary[p])))
			{
				break;
			}
		}
		if(i == n)
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
