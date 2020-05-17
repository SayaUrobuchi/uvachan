#include <stdio.h>

int main()
{
	int n, m, o, i, j, t, sum;
	while (scanf("%d%d%d", &n, &m, &o) == 3)
	{
		for (i=n; i<=m; i++)
		{
			for (t=i, sum=0; t; t/=10)
			{
				sum += t%10;
			}
			if (sum == o)
			{
				break;
			}
		}
		for (j=m; j>=n; j--)
		{
			for (t=j, sum=0; t; t/=10)
			{
				sum += t%10;
			}
			if (sum == o)
			{
				break;
			}
		}
		printf("%d\n%d\n", i, j);
	}
	return 0;
}
