#include <iostream>

int n;
int py[1048576];

double calc(double t)
{
	int i;
	double res;
	for (i=0, res=0; i<n; i++)
	{
		res += (py[i]-t)*(py[i]-t)/2;
	}
	return res;
}

int main()
{
	int i, big, small, x;
	double p, q, t, u;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, big=-1e9, small=1e9; i<n; i++)
		{
			scanf("%d%d", &x, &py[i]);
			py[i] -= x;
			if (py[i] < small)
			{
				small = py[i];
			}
			if (py[i] > big)
			{
				big = py[i];
			}
		}
		//printf("%d %d\n", small, big);
		for (p=small, q=big; q-p>1e-7; )
		{
			t = p + (q-p)/3;
			u = q - (q-p)/3;
			if (calc(t) < calc(u))
			{
				q = u;
			}
			else
			{
				p = t;
			}
		}
		//printf("%.10lf %.10lf\n", p, q);
		printf("%.10lf\n", (p+q)/2);
	}
	return 0;
}
