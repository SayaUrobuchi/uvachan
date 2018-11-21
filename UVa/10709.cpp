#include <stdio.h>
#include <string.h>
#include <math.h>

char buf1[2008], buf2[2008];

struct point
{
	int x, y;
};

struct vector
{
	int x, y;
};

double min(double p, double q)
{
	if(p < q)
	{
		return p;
	}
	return q;
}

int ab(int now)
{
	if(now < 0)
	{
		return -now;
	}
	return now;
}

double dist(struct point p, struct point q)
{
	return sqrt((p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y));
}

double length(struct vector v)
{
	return sqrt(v.x*v.x+v.y*v.y);
}

int cross(struct vector p, struct vector q)
{
	return p.x * q.y - p.y * q.x;
}

int dot(struct vector p, struct vector q)
{
	return p.x * q.x + p.y * q.y;
}

double ptol(struct point p, struct point p1, struct point p2)
{
	struct vector v1, v2;
	v1.x = p.x - p1.x;
	v1.y = p.y - p1.y;
	v2.x = p2.x - p1.x;
	v2.y = p2.y - p1.y;
	return ab(cross(v1, v2)) / length(v2);
}

double ptols(struct point p, struct point p1, struct point p2)
{
	struct vector v1, v2, v3, v4;
	v1.x = p.x - p1.x;
	v1.y = p.y - p1.y;
	v2.x = p2.x - p1.x;
	v2.y = p2.y - p1.y;
	v3.x = p.x - p2.x;
	v3.y = p.y - p2.y;
	v4.x = p1.x - p2.x;
	v4.y = p1.y - p2.y;
	if(dot(v1, v2) > 0 && dot(v3, v4) > 0)
	{
		return ab(cross(v1, v2)) / length(v2);
	}
	return min(dist(p, p1), dist(p, p2));
}

int main()
{
	double ans;
	struct point p1, p2, p3, p4;
	struct vector v1, v2, v3, v4, v5, v6;
	while(scanf("%d%d%d%d%s", &p1.x, &p1.y, &p2.x, &p2.y, buf1) == 5)
	{
		scanf("%d%d%d%d%s", &p3.x, &p3.y, &p4.x, &p4.y, buf2);
		if(!strcmp(buf1, "END") && !strcmp(buf2, "END"))
		{
			break;
		}
		if(!strcmp(buf1, "L") && !strcmp(buf2, "L"))
		{
			v1.x = p2.x - p1.x;
			v1.y = p2.y - p1.y;
			v2.x = p4.x - p3.x;
			v2.y = p4.y - p3.y;
			if(cross(v1, v2) == 0)
			{
				ans = ptol(p1, p3, p4);
			}
			else
			{
				ans = 0.0;
			}
		}
		else if(!strcmp(buf1, "LS") && !strcmp(buf2, "LS"))
		{
			v1.x = p4.x - p3.x;
			v1.y = p4.y - p3.y;
			v2.x = p1.x - p3.x;
			v2.y = p1.y - p3.y;
			v3.x = p2.x - p3.x;
			v3.y = p2.y - p3.y;
			v4.x = p2.x - p1.x;
			v4.y = p2.y - p1.y;
			v5.x = p3.x - p1.x;
			v5.y = p3.y - p1.y;
			v6.x = p4.x - p1.x;
			v6.y = p4.y - p1.y;
			if(((cross(v1, v2) > 0 && cross(v1, v3) < 0) || (cross(v1, v2) < 0 && cross(v1, v3) > 0)) && 
				((cross(v4, v5) > 0 && cross(v4, v6) < 0) || (cross(v4, v5) < 0 && cross(v4, v6) > 0)))
			{
				ans = 0.0;
			}
			else
			{
				ans = min(ptols(p1, p3, p4), min(ptols(p2, p3, p4), min(ptols(p3, p1, p2), ptols(p4, p1, p2))));
			}
		}
		else
		{
			if(!strcmp(buf1, "LS"))
			{
				v1.x = p4.x - p3.x;
				v1.y = p4.y - p3.y;
				v2.x = p1.x - p3.x;
				v2.y = p1.y - p3.y;
				v3.x = p2.x - p3.x;
				v3.y = p2.y - p3.y;
				if((cross(v1, v2) > 0 && cross(v1, v3) < 0) || (cross(v1, v2) < 0 && cross(v1, v3) > 0))
				{
					ans = 0.0;
				}
				else
				{
					ans = min(ptol(p1, p3, p4), ptol(p2, p3, p4));
				}
			}
			else
			{
				v1.x = p2.x - p1.x;
				v1.y = p2.y - p1.y;
				v2.x = p3.x - p1.x;
				v2.y = p3.y - p1.y;
				v3.x = p4.x - p1.x;
				v3.y = p4.y - p1.y;
				if((cross(v1, v2) > 0 && cross(v1, v3) < 0) || (cross(v1, v2) < 0 && cross(v1, v3) > 0))
				{
					ans = 0.0;
				}
				else
				{
					ans = min(ptol(p3, p1, p2), ptol(p4, p1, p2));
				}
			}
		}
		printf("%.5lf\n", ans);
	}
	return 0;
}
