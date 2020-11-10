#include <iostream>

int main()
{
	int n, m, i, b;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0, b=1; i<m; i++, b*=10);
		if (n%b >= (b>>1))
		{
			n = ((n-1)/b+1) * b;
		}
		else
		{
			n = (n/b) * b;
		}
		printf("%d\n", n);
	}
	return 0;
}
