#include <stdio.h>

int main()
{
	int n, i, a, b, p, q;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, a=0, b=0; i<n; i++)
		{
			scanf("%d%d", &p, &q);
			a += p;
			b += q;
		}
		if (b <= 60*a)
		{
			puts("measurement error");
		}
		else
		{
			printf("%.10lf\n", b/60.0/a);
		}
	}
	return 0;
}
