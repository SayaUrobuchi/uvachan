#include <stdio.h>

double cross(double x1, double y1, double x2, double y2)
{
	return x1*y2 - x2*y1;
}

double max(double p, double q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

double min(double p, double q)
{
	if(p < q)
	{
		return p;
	}
	return q;
}

double ab(double now)
{
	if(now < 0)
	{
		return -now;
	}
	return now;
}

int zero(double now)
{
	return ab(now) < 0.00000001;
}

int main()
{
	int i, j, c;
	double x1, y1, x2, y2, x3, y3, maxx, minx, maxy, miny, px, py, t1, t2;
	while(scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3) == 6)
	{
		if(!x1 && !y1 && !x2 && !y2 && !x3 && !y3)
		{
			break;
		}
		maxx = max(-1, max(x1, max(x2, x3)));
		minx = min(1000, min(x1, min(x2, x3)));
		maxy = max(-1, max(y1, max(y2, y3)));
		miny = min(1000, min(y1, min(y2, y3)));
		maxx = min(maxx, 99);
		minx = max(minx, 1);
		maxy = min(maxy, 99);
		miny = max(miny, 1);
		minx += (minx != (int)minx);
		miny += (miny != (int)miny);
		px = (x1+x2+x3) / 3;
		py = (y1+y2+y3) / 3;
		for(i=minx, c=0; i<=maxx; i++)
		{
			for(j=miny; j<=maxy; j++)
			{
				t1 = cross(i-x1, j-y1, x2-x1, y2-y1);
				t2 = cross(px-x1, py-y1, x2-x1, y2-y1);
				if(zero(t1) || (!zero(t2) && t1*t2 > 0))
				{
					t1 = cross(i-x2, j-y2, x3-x2, y3-y2);
					t2 = cross(px-x2, py-y2, x3-x2, y3-y2);
					if(zero(t1) || (!zero(t2) && t1*t2 > 0))
					{
						t1 = cross(i-x3, j-y3, x1-x3, y1-y3);
						t2 = cross(px-x3, py-y3, x1-x3, y1-y3);
						if(zero(t1) || (!zero(t2) && t1*t2 > 0))
						{
							c++;
						}
					}
				}
			}
		}
		printf("%4d\n", c);
	}
	return 0;
}
