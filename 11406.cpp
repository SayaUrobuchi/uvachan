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
	if(x + rad > siz / 2.0)
	{
		x = siz/2.0 - rad;
	}
	if(x - rad < -(siz / 2.0))
	{
		x = -(siz/2.0) + rad;
	}
	if(y + rad > siz / 2.0)
	{
		y = siz/2.0 - rad;
	}
	if(y - rad < -(siz / 2.0))
	{
		y = -(siz/2.0) + rad;
	}
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
		if(rad > siz)
		{
			printf("0\n");
			continue;
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
					if(!equal((a-c)/(a-e), (b-d)/(b-f)))
					{
						x = ((2*b-2*f)*(a*a+b*b-c*c-d*d)-(2*b-2*d)*(a*a+b*b-e*e-f*f)) / 
							((2*b-2*f)*(2*a-2*c)-(2*a-2*e)*(2*b-2*d));
						y = ((a*a+b*b-c*c-d*d)-((2*a-2*c)*x)) / (2*b-2*d);
						chk_ans(x, y);
					}
				}
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
