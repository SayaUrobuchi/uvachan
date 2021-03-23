#include <iostream>

int ary[1048576];

int main()
{
	int n, i, a, b, t, sum;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, sum=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			sum += ary[i];
		}
		a = b = -1;
		if (sum % 3 == 0)
		{
			sum /= 3;
			for (i=0, t=ary[i]; i<n&&t<sum; i++, t+=ary[i]);
			if (t == sum)
			{
				a = i;
				for (i=a+1, t=ary[i]; i<n&&t<sum; i++, t+=ary[i]);
				if (t == sum)
				{
					b = i;
				}
			}
		}
		if (b == -1)
		{
			puts("-1");
		}
		else
		{
			printf("%d %d\n", a+1, b+1);
		}
	}
	return 0;
}
