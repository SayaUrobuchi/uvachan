#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ary[200];
char str[200][81], final[200][81];

int search(int i, char* s)
{
	for(; strcmp(final[i], s); i--);
	return i;
}

int comp(const void *p, const void *q)
{
	return *(int*)q - *(int*)p;
}

int main()
{
	int count, n, i, j, k, temp;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		gets(str[0]);
		for(i=0; i<n; i++)
		{
			gets(str[i]);
		}
		for(i=0; i<n; i++)
		{
			gets(final[i]);
		}
		for(i=n-1, j=n-1, k=0; i>-1; i--)
		{
			if(!strcmp(final[j], str[i]))
			{
				j--;
			}
			else
			{
				ary[k++] = search(j-1, str[i]);
			}
		}
		qsort(ary, k, sizeof(int), comp);
		for(i=0; i<k; i++)
		{
			printf("%s\n", final[ary[i]]);
		}
		printf("\n");
	}
	return 0;
}
