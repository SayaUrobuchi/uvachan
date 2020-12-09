#include <iostream>

int ary[1048576];

int main()
{
	int n, i;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		for (i=n-1; i>=0; i--)
		{
			printf("%d\n", ary[i]);
		}
	}
	return 0;
}
