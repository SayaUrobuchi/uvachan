#include <stdio.h>
#include <math.h>

int res, n, siz;
double rad;
double px[20], py[20];

double ab(double p)
{
	return p>0 ? p : -p;
}

int equal(double p, double q)
{
	return ab(p-q) < 1e-10;
}

double dis(double x1, double y1, double x2, double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int chk_ans(double x, double y)
{
	int temp, i;
	for(i=0, temp=0; i<n; i++)
	{
		if(dis(x, y, px[i], py[i]) <= rad)
		{
			temp++;
		}
	}
	if(temp > res)
	{
		res = temp;
	}
	return res;
}

int main()
{
	int count, i, j, k;
	double a, b, c, d, e, f, x, y;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%lf%d", &siz, &rad, &n);
		for(i=0; i<n; i++)
		{
			scanf("%lf%lf", &px[i], &py[i]);
		}
		for(i=0, res=0; i<n; i++)
		{
			chk_ans(px[i], py[i]);
			for(j=i+1; j<n; j++)
			{
				chk_ans((px[i]+px[j])/2, (py[i]+py[j])/2);
				for(k=j+1; k<n; k++)
				{
					a = px[i];
					b = py[i];
					c = px[j];
					d = py[j];
					e = px[k];
					f = py[k];
					if(!equal((a-c)*(b-f), (b-d)*(a-e)))
					{
						/* 
						(a-x)(a-x)+(b-y)(b-y)=(c-x)(c-x)+(d-y)(d-y)
						(a-x)(a-x)+(b-y)(b-y)=(e-x)(e-x)+(f-y)(f-y)
						a*a-2ax+b*b-2yb=c*c-2cx+d*d-2dy
						2cx-2ax=c*c+d*d-a*a-b*b+2by-2dy
						x=(c*c+d*d-a*a-b*b+2by-2dy)/(2c-2a)
						x=(e*e+f*f-a*a-b*b+2by-2fy)/(2e-2a)
						(c*c+d*d-a*a-b*b+2by-2dy)/(2c-2a)=(e*e+f*f-a*a-b*b+2by-2fy)/(2e-2a)
						(c*c+d*d-a*a-b*b+2by-2dy)*(2e-2a)=(e*e+f*f-a*a-b*b+2by-2fy)*(2c-2a)
						(c*c+d*d-a*a-b*b)*(2e-2a)+(2by-2dy)*(2e-2a)=(e*e+f*f-a*a-b*b)*(2c-2a)+(2by-2fy)*(2c-2a)
						(c*c+d*d-a*a-b*b)*(2e-2a)-(e*e+f*f-a*a-b*b)*(2c-2a)=(2by-2fy)*(2c-2a)-(2by-2dy)*(2e-2a)
						(c*c+d*d-a*a-b*b)*(2e-2a)-(e*e+f*f-a*a-b*b)*(2c-2a)=4cby-4cfy-4aby+4afy-4bey+4edy+4aby-4ady
						(c*c+d*d-a*a-b*b)*(2e-2a)-(e*e+f*f-a*a-b*b)*(2c-2a)=4cby-4cfy+4afy-4bey+4edy-4ady
						4cby-4cfy+4afy-4bey+4edy-4ady=(c*c+d*d-a*a-b*b)*(2e-2a)-(e*e+f*f-a*a-b*b)*(2c-2a)
						(4cb-4cf+4af-4be+4ed-4ad)y=(c*c+d*d-a*a-b*b)*(2e-2a)-(e*e+f*f-a*a-b*b)*(2c-2a)
						y=((c*c+d*d-a*a-b*b)*(2e-2a)-(e*e+f*f-a*a-b*b)*(2c-2a))/(4cb-4cf+4af-4be+4ed-4ad)
						x=(c*c+d*d-a*a-b*b+2by-2dy)/(2c-2a)
						*/
						y = ((c*c+d*d-a*a-b*b)*(2*e-2*a)-(e*e+f*f-a*a-b*b)*(2*c-2*a))/(4*c*b-4*c*f+4*a*f-4*b*e+4*e*d-4*a*d);
						if (!equal(c, a))
						{
							x = (c*c+d*d-a*a-b*b+2*b*y-2*d*y)/(2*c-2*a);
						}
						else
						{
							x = (e*e+f*f-a*a-b*b+2*b*y-2*f*y)/(2*e-2*a);
						}
						chk_ans(x, y);
					}
				}
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
