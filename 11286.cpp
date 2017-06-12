#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int list[5];
int index[10001];
char ary[10001][16];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int scomp(const void *p, const void *q)
{
	return strcmp(ary[*(int*)p], ary[*(int*)q]);
}

int main()
{
	int n, i, j, maxpop, c;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			for(j=0; j<5; j++)
			{
				scanf("%d", &list[j]);
			}
			qsort(list, 5, sizeof(int), comp);
			sprintf(ary[i], "%d%d%d%d%d", list[0], list[1], list[2], list[3], list[4]);
			index[i] = i;
		}
		qsort(index, n, sizeof(int), scomp);
		maxpop = 1;
		c = 0;
		for(i=0; i<n; i=j)
		{
			for(j=i+1; j<n; j++)
			{
				if(strcmp(ary[index[j]], ary[index[i]]))
				{
					break;
				}
			}
			if(j - i == maxpop)
			{
				c += j - i;
			}
			else if(j - i > maxpop)
			{
				maxpop = j - i;
				c = j - i;
			}
		}
		printf("%d\n", c);
	}
	return 0;
}
