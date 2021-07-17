#include <iostream>

int main()
{
	int n, i;
	long long sum;
	while (scanf("%d", &n) == 1)
	{
		for (i=2, sum=1; i*i<=n; i++)
		{
			if (n%i == 0)
			{
				sum += i;
				if (i*i != n)
				{
					sum += n/i;
				}
			}
		}
		if (sum == n)
		{
			printf("%d perfect\n", n);
		}
		else if (std::abs(sum-n) <= 2)
		{
			printf("%d almost perfect\n", n);
		}
		else
		{
			printf("%d not perfect\n", n);
		}
	}
	return 0;
}
