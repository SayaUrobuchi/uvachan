#include <iostream>

int ary[128];

int main()
{
	int i, j, k, n;
	ary[0] = 2;
	for (i=3, j=1; i<100; i+=2)
	{
		for (k=3; k*k<=i; k+=2)
		{
			if (i%k == 0)
			{
				break;
			}
		}
		if (k*k > i)
		{
			ary[j] = i;
			++j;
		}
	}
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<j; i++)
		{
			if (n%ary[i] != 0)
			{
				break;
			}
		}
		printf("%d\n", ary[i]);
	}
	return 0;
}
