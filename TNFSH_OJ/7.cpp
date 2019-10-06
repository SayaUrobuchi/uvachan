#include <stdio.h>

int ary[32];

int main()
{
	int count, n, i, j;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=0; i<=n; i++)
		{
			scanf("%d", &ary[i]);
		}
		for (i=0; i<n; i++)
		{
			for (j=0; j<n-i; j++)
			{
				ary[j] = ary[j+1] - ary[j];
			}
		}
		printf("%d\n", ary[0]);
	}
	return 0;
}
