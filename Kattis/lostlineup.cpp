#include <stdio.h>

int ary[1048576];

int main()
{
	int n, i, t;
	while (scanf("%d", &n) == 1)
	{
		for (i=2; i<=n; i++)
		{
			scanf("%d", &t);
			ary[t] = i;
		}
		printf("1");
		for (i=0; i<n-1; i++)
		{
			printf(" %d", ary[i]);
		}
		puts("");
	}
	return 0;
}
