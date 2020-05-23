#include <stdio.h>

int main()
{
	int n, i, j, t, last, miss;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, last=0, miss=0; i<n; i++)
		{
			scanf("%d", &t);
			for (j=last+1; j<t; j++)
			{
				//printf("missed::");
				printf("%d\n", j);
				miss = 1;
			}
			last = t;
		}
		if (!miss)
		{
			puts("good job");
		}
	}
	return 0;
}
