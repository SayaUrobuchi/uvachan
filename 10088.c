#include <stdio.h>

int x[1005], y[1005];

int ab(int n)
{
	return n>0 ? n : -n;
}

int gcd(int p, int q)
{
	return q ? (p%q ? gcd(q, p%q) : q) : p;
}

int main()
{
	int n, i;
	double a, s;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		for(i=0, a=0, s=0; i<n; i++)
		{
			scanf("%d%d", &x[i], &y[i]);
			if(i)
			{
				a += (long long)x[i-1] * y[i] - (long long)x[i] * y[i-1];
				s += gcd(ab(x[i]-x[i-1]), ab(y[i]-y[i-1]));
			}
		}
		a += (long long)x[n-1] * y[0] - (long long)x[0] * y[n-1];
		s += gcd(ab(x[0]-x[n-1]), ab(y[0]-y[n-1]));
		a /= 2;
		if(a < 0)
		{
			a = -a;
		}
		a++;
		a -= s/2;
		printf("%.0lf\n", a);
	}
	return 0;
}

