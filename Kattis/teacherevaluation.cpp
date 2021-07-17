#include <iostream>

int main()
{
	int n, m, i, t, sum, need;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0, sum=0; i<n; i++)
		{
			scanf("%d", &t);
			sum += t;
		}
		if (m == 100)
		{
			puts("impossible");
			continue;
		}
		for (i=n+1; ; i++)
		{
			need = (i * m) - sum;
			if (need <= 100)
			{
				break;
			}
			sum += 100;
		}
		printf("%d\n", i-n);
	}
	return 0;
}
