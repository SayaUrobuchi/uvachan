#include <stdio.h>

int gcd(int p, int q)
{
	while ((p%=q) && (q%=p));
	return p+q;
}

int main()
{
	int n, t, i, p, r;
	while (scanf("%d%d", &n, &t) == 2)
	{
		for (i=1; i<n; i++)
		{
			scanf("%d", &p);
			r = gcd(p, t);
			printf("%d/%d\n", t/r, p/r);
		}
	}
	return 0;
}