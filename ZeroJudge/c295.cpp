#include <stdio.h>

int ary[1024];

int main()
{
	int n, m, i, j, sum, last, p;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0, sum=0; i<n; i++)
		{
			for (j=0, last=-1; j<m; j++)
			{
				scanf("%d", &p);
				if (p > last)
				{
					last = p;
				}
			}
			ary[i] = last;
			sum += last;
		}
		printf("%d\n", sum);
		for (i=0, j=0; i<n; i++)
		{
			if (sum % ary[i] == 0)
			{
				printf(j?" %d":"%d", ary[i]);
				j++;
			}
		}
		if (!j)
		{
			puts("-1");
		}
	}
	return 0;
}
