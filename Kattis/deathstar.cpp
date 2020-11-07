#include <iostream>

int ary[1024];

int main()
{
	int n, i, j, t;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			ary[i] = 0;
		}
		for (i=0; i<n; i++)
		{
			for (j=0; j<n; j++)
			{
				scanf("%d", &t);
				ary[i] |= t;
				ary[j] |= t;
			}
		}
		printf("%d", ary[0]);
		for (i=1; i<n; i++)
		{
			printf(" %d", ary[i]);
		}
		puts("");
	}
	return 0;
}
