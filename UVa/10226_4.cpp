#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int index[1000001];
char name[1000001][31];
char buf[31];

int comp(const void *p, const void *q)
{
	return strcmp(name[*(int*)p], name[*(int*)q]);
}

int main()
{
	int count, n, i, j;
	scanf("%d", &count);
	gets(buf);
	gets(buf);
	while(count--)
	{
		n = 0;
		while(gets(name[n]))
		{
			if(!name[n][0])
			{
				break;
			}
			index[n] = n;
			n++;
		}
		qsort(index, n, sizeof(int), comp);
		for(i=0; i<n; i=j)
		{
			for(j=i+1; j<n; j++)
			{
				if(strcmp(name[index[i]], name[index[j]]))
				{
					break;
				}
			}
			printf("%s %.4lf\n", name[index[i]], (j-i)*100.0/n);
		}
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
