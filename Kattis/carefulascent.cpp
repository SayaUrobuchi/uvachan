#include <stdio.h>

int main()
{
	int x, y, n, i, p, q;
	double f, rat;
	while (scanf("%d%d", &x, &y) == 2)
	{
		scanf("%d", &n);
		for (i=0, rat=y; i<n; i++)
		{
			scanf("%d%d%lf", &p, &q, &f);
			rat -= q-p;
			rat += (q-p)*f;
		}
		//printf("%.10lf\n", rat);
		printf("%.10lf\n", (x/rat));
	}
	return 0;
}
