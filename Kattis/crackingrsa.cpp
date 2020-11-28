#include <iostream>

int main()
{
	int count, n, m, i, j, phi;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &n, &m);
		for (i=2; i*i<=n; i++)
		{
			if (n % i == 0)
			{
				break;
			}
		}
		j = n / i;
		phi = (i-1) * (j-1);
		for (i=2; (long long)i*m%phi!=1; i++);
		printf("%d\n", i);
	}
	return 0;
}
