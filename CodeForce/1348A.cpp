#include <stdio.h>

int main()
{
	int count, n, i;
	long long a, b;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=1, a=0, b=0; i<=n; i++)
		{
			if (i == n || i+i < n)
			{
				a += (1<<i);
			}
			else
			{
				b += (1<<i);
			}
		}
		printf("%lld\n", a>b?a-b:b-a);
	}
	return 0;
}
