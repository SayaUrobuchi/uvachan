#include <iostream>

double px[128], py[128];

int main()
{
	int n, i, j, a, b;
	double d;
	while (scanf("%lf%d", &d, &n) == 2)
	{
		if (d == 0 && n == 0)
		{
			break;
		}
		d *= d;
		for (a=0, b=0, i=0; i<n; i++)
		{
			scanf("%lf%lf", &px[i], &py[i]);
		}
		for (i=0; i<n; i++)
		{
			for (j=0; j<n; j++)
			{
				if (i != j)
				{
					if ((px[i]-px[j])*(px[i]-px[j])+(py[i]-py[j])*(py[i]-py[j]) <= d)
					{
						break;
					}
				}
			}
			if (j < n)
			{
				++a;
			}
			else
			{
				++b;
			}
		}
		printf("%d sour, %d sweet\n", a, b);
	}
	return 0;
}
