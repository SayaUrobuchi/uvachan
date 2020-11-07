#include <iostream>
#include <cmath>

const double PI = acos(-1);

double px[1024], py[1024], pr[1024];
char nam[1024][32];

int main()
{
	int count, n, m, i, j;
	double x, y, d;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=0; i<n; i++)
		{
			scanf("%lf%lf%lf%s", &px[i], &py[i], &d, nam[i]);
			pr[i] = d/PI;
		}
		scanf("%d", &m);
		for (i=0; i<m; i++)
		{
			scanf("%lf%lf", &x, &y);
			for (j=n-1; j>=0; j--)
			{
				if ((x-px[j])*(x-px[j])+(y-py[j])*(y-py[j]) <= pr[j])
				{
					puts(nam[j]);
					break;
				}
			}
			if (j < 0)
			{
				puts("white");
			}
		}
	}
	return 0;
}
