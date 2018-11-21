#include <stdio.h>

int main()
{
	int count;
	int n, i, res;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		if (n & 1)
		{
			puts("deficient");
			continue;
		}
		res = 1;
		for (i=2; i*i<=n&&res<=n; i++)
		{
			if (n % i == 0)
			{
				res += i;
				if (i*i != n)
				{
					res += n/i;
				}
			}
		}
		if (res > n)
		{
			puts("abundant");
		}
		else if (res == n)
		{
			puts("perfect");
		}
		else
		{
			puts("deficient");
		}
	}
    return 0;
}
