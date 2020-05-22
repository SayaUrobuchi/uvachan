#include <stdio.h>

double score[128];

int main()
{
	int n, i, t;
	double sum, eff, revsum, rev;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, sum=0, eff=1; i<n; i++, eff*=0.8)
		{
			scanf("%d", &t);
			score[i] = t*eff;
			sum += score[i];
		}
		printf("%.10lf\n", sum/5);
		for (i=n-1, revsum=0, rev=0; i>=0; i--)
		{
			sum -= score[i];
			revsum += sum + rev;
			rev += score[i] / .8;
		}
		printf("%.10lf\n", revsum/n/5);
	}
	return 0;
}
