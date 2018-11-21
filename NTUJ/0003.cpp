#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ptr[1010], pre[1010];
char name[1010][25];

int comp(const void *p, const void *q)
{
	return strcmp(name[*(int*)p], name[*(int*)q]);
}

int main()
{
	int n, i, j, f, b;
	n = 1;
	while(gets(name[n]))
	{
		ptr[n] = n;
		n++;
	}
	qsort(ptr, n, sizeof(int), comp);
	for(i=1; i<n; i++)
	{
		for(j=0, f=1, b=1; f||b; j++)
		{
			if(f && name[ptr[i-1]][j] != name[ptr[i]][j])
			{
				f = 0;
			}
			if(b && name[ptr[i+1]][j] != name[ptr[i]][j])
			{
				b = 0;
			}
		}
		pre[ptr[i]] = j;
	}
	for(i=1; i<n; i++)
	{
		printf("%s %.*s\n", name[i], pre[i], name[i]);
	}
	scanf(" ");
	return 0;
}
