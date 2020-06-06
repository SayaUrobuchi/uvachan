#include <stdio.h>
#include <math.h>

const double EPS = 1e-6;

double amount[32], rat[32];
char nam[32][32];

int main()
{
	int cas, count, n, m, o, i, p;
	cas = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d%d", &n, &m, &o);
		for (i=0, p=-1; i<n; i++)
		{
			scanf("%s%lf%lf", nam[i], &amount[i], &rat[i]);
			if (fabs(rat[i]-100) < EPS)
			{
				p = i;
			}
		}
		printf("Recipe # %d\n", ++cas);
		for (i=0; i<n; i++)
		{
			printf("%s %.10lf\n", nam[i], amount[p]*rat[i]*o/m/100);
		}
		puts("----------------------------------------");
	}
	return 0;
}
