#include <stdio.h>

int main()
{
	int n, m, i, t, u;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		for (t=n, m=0; t; m+=t%10, t/=10);
		for (i=n*11; ; i+=n)
		{
			for (t=i, u=0; t; u+=t%10, t/=10);
			if (u == m)
			{
				break;
			}
		}
		printf("%d\n", i/n);
	}
	return 0;
}