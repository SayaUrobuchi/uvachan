#include <stdio.h>

int ary[8], tbl[8] = {1, 1, 2, 2, 2, 8};

int main()
{
	int i;
	while (scanf("%d", &ary[0]) == 1)
	{
		for (i=1; i<6; i++)
		{
			scanf("%d", &ary[i]);
		}
		printf("%d", tbl[0]-ary[0]);
		for (i=1; i<6; i++)
		{
			printf(" %d", tbl[i]-ary[i]);
		}
		puts("");
	}
	return 0;
}
