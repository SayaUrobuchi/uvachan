#include <iostream>

int gcd(int a, int b)
{
	while ((a%=b) && (b%=a));
	return a+b;
}

int main()
{
	int n, m, i, k, t;
	while (scanf("%d%d", &n, &m) == 2)
	{
		k = 360;
		for (i=0; i<n; i++)
		{
			scanf("%d", &t);
			k = gcd(k, t);
		}
		for (i=0; i<m; i++)
		{
			scanf("%d", &t);
			puts(t%k==0?"YES":"NO");
		}
	}
	return 0;
}
