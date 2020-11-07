#include <iostream>

int main()
{
	int i, spd, best;
	double lost, cost, need, tim, c, m;
	while (scanf("%lf%lf%lf", &c, &lost, &m) == 3)
	{
		c /= 2;
		for (i=0, best=-1; i<6; i++)
		{
			scanf("%d%lf", &spd, &cost);
			if (spd > best)
			{
				tim = m/spd;
				need = m / cost + tim * lost;
				//printf("%.10lf %.10lf\n", m/cost, tim);
				if (need <= c)
				{
					best = spd;
				}
			}
		}
		if (best == -1)
		{
			puts("NO");
		}
		else
		{
			printf("YES %d\n", best);
		}
	}
	return 0;
}
