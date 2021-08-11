#include <iostream>
#include <cmath>

const double PI = acos(-1);

int n;
double ary[32], bry[32];

double calc(double x)
{
	int i;
	double t, res;
	for (i=1, t=x, res=0; i<=n+n+1; i++, t*=x)
	{
		res += t*bry[i];
	}
	return res*PI;
}

int main()
{
	int cas, i, j, c;
	double a, b, t, u, v, p, q, last, total;
	bool first;
	cas = 0;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<=n; i++)
		{
			scanf("%lf", &ary[i]);
		}
		for (i=0; i<=n+n; i++)
		{
			t = 0;
			for (j=0; j<=i; j++)
			{
				t += ary[j] * ary[i-j];
			}
			bry[i+1] = t / (i+1);
		}
		scanf("%lf%lf%d", &a, &b, &c);
		total = calc(b) - calc(a);
		printf("Case %d: %.2lf\n", ++cas, total);
		for (i=1, v=c, first=true, last=a; i<=8&&v<total; i++, v+=c)
		{
			if (!first)
			{
				putchar(' ');
			}
			first = false;
			for (p=last, q=b; q-p>1e-5; )
			{
				t = (p+q)/2;
				u = calc(t) - calc(last);
				if (u < c)
				{
					p = t;
				}
				else
				{
					q = t;
				}
			}
			last = (p+q)/2;
			printf("%.2lf", last-a);
		}
		if (first)
		{
			puts("insufficient volume");
		}
		else
		{
			puts("");
		}
	}
	return 0;
}
