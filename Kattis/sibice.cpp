#include <stdio.h>

int main()
{
	int n, p, q, r, i;
	while (scanf("%d%d%d", &n, &p, &q) == 3)
	{
		p *= p;
		q *= q;
		for (i=0; i<n; i++)
		{
			scanf("%d", &r);
			puts(r*r<=p+q ? "DA" : "NE");
		}
	}
	return 0;
}
