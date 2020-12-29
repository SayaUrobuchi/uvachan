#include <iostream>

int main()
{
	int count;
	unsigned long long n, i, j;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%llu", &n);
		for (i=n; ; i++)
		{
			for (j=i; j; j/=10)
			{
				if ((j%10) && i%(j%10))
				{
					break;
				}
			}
			if (!j)
			{
				break;
			}
		}
		printf("%llu\n", i);
	}
	return 0;
}
