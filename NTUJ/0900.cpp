#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ary[1000005];
char buf[1000005];

int comp(const void *p, const void *q)
{
	return *(int*)p > *(int*)q ? 1 : -1;
}

int main()
{
	int count, i, j, n, small, big;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0, j=0, small=0, big=0; i<n; i++)
		{
			scanf("%s", buf);
			if(strcmp(buf, "dog") == 0)
			{
				small++;
			}
			else if(strcmp(buf, "DOG") == 0)
			{
				big++;
			}
			else
			{
				ary[j++] = atoi(buf);
			}
		}
		if(small + big == 0 || small + big > 1 || j == 0)
		{
			printf("SAFE\n");
		}
		else
		{
			qsort(ary, j, sizeof(int), comp);
			if(small)
			{
				printf("%d\n", ary[0]);
			}
			else
			{
				printf("%d\n", ary[j-1]);
			}
		}
	}
	return 0;
}
