#include <iostream>
#include <cmath>

double ary[1024], bry[1024];

double calc(double w, double h, double ang, double r, int level)
{
	double a, b, c;
	a = r*tan(ang);
	b = w - a;
	c = (r+b+h);
	return bry[level-1]*r*r/h/h + c*c/4 - r*r/2;
}

int main()
{
	int i, n;
	double w, h, p, q, mid, ang, ans, t0, t1, a, b;
	while (scanf("%lf%lf%d", &w, &h, &n) == 3)
	{
		ang = atan2(w, h);
		bry[0] = (w+h)*(w+h)/4;
		for (i=1; i<=n; i++)
		{
			for (p=0, q=h; q-p>1e-12; )
			{
				t0 = p + (q-p)/3;
				t1 = q - (q-p)/3;
				a = calc(w, h, ang, t0, i);
				b = calc(w, h, ang, t1, i);
				if (a < b)
				{
					q = t1;
				}
				else
				{
					p = t0;
				}
			}
			ary[i] = (p+q)/2/h;
			bry[i] = calc(w, h, ang, h*ary[i], i);
		}
		for (i=n-1; i>0; i--)
		{
			ary[i] *= ary[i+1];
		}
		printf("%.10lf\n", bry[n]);
		for (i=1; i<=n&&i<=10; i++)
		{
			printf("%.10lf\n", ary[i]*w);
		}
	} 
	return 0;
}
