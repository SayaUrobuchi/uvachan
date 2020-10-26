#include <iostream>

int ary[1048576];

int main()
{
	int n, i, j, last, t;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, j=0, last=0; i<n; i++)
		{
			scanf("%d", &t);
			if (t > last)
			{
				last = t;
				ary[j++] = t;
			}
		}
		printf("%d\n%d", j, ary[0]);
		for (i=1; i<j; i++)
		{
			printf(" %d", ary[i]);
		}
		puts("");
	}
	return 0;
}
