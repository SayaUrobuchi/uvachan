#include <stdio.h>

int main()
{
	int n, m, i, p, q;
	long long t;
	while (scanf("%d%d", &m, &n) == 2)
	{
		for (i=0, t=0; i<n; i++)
		{
			scanf("%d%d", &p, &q);
			t += p*q;
		}
		printf("%lld\n", t/m);
	}
	return 0;
}