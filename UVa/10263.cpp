#include <stdio.h>
#include <math.h>

#define N 1005
#define INF 1e30

double x, y, mx, my, ans;
double px[N], py[N];

struct vector
{
	double x, y;
};

double ab(double now)
{
	if(now < 0)
	{
		return -now;
	}
	return now;
}

double dot(struct vector p, struct vector q)
{
	return p.x * q.x + p.y * q.y;
}

double cross(struct vector p, struct vector q)
{
	return p.x * q.y - p.y * q.x;
}

double length(struct vector p)
{
	return sqrt(p.x*p.x+p.y*p.y);
}

double getdist(double p, double q)
{
	return sqrt(p*p+q*q);
}

void calc(int p, int q)
{
	struct vector v1, v2, v3, v4;
	double d1, d2, rate;
	v1.x = px[p] - px[q];
	v1.y = py[p] - py[q];
	v2.x = mx - px[q];
	v2.y = my - py[q];
	v3.x = px[q] - px[p];
	v3.y = py[q] - py[p];
	v4.x = mx - px[p];
	v4.y = my - py[p];
	if(dot(v1, v2) > 0 && dot(v3, v4) > 0)
	{
		d1 = ab(cross(v1, v2)) / length(v1);
		if(d1 < ans)
		{
			ans = d1;
			v3.x = v1.y;
			v3.y = -v1.x;
			rate = ab(cross(v2, v3)) / ab(cross(v1, v3));
			x = px[q] + v1.x * rate;
			y = py[q] + v1.y * rate;
		}
	}
	else
	{
		d1 = getdist(px[p]-mx, py[p]-my);
		d2 = getdist(px[q]-mx, py[q]-my);
		if(d1 < d2)
		{
			if(d1 < ans)
			{
				ans = d1;
				x = px[p];
				y = py[p];
			}
		}
		else
		{
			if(d2 < ans)
			{
				ans = d2;
				x = px[q];
				y = py[q];
			}
		}
	}
}

int main()
{
	int n, i;
	while(scanf("%lf%lf", &mx, &my) == 2)
	{
		scanf("%d", &n);
		for(i=0, ans=INF; i<=n; i++)
		{
			scanf("%lf%lf", &px[i], &py[i]);
			if(i > 0)
			{
				calc(i, i-1);
			}
		}
		printf("%.4lf\n%.4lf\n", x, y);
	}
	return 0;
}
