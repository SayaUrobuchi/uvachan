#include <stdio.h>
#include <math.h>

int m;

typedef struct rect
{
	double x1, y1, x2, y2;
}rect;

rect ary[1005];

double max(double p, double q)
{
	return p>q ? p : q;
}

double min(double p, double q)
{
	return p<q ? p : q;
}

int valid(rect *p)
{
	return (p->x1<p->x2&&fabs(p->x1-p->x2)>1e-10) && (p->y1<p->y2&&fabs(p->y1-p->y2)>1e-10);
}

int intersect(rect *p, rect *q)
{
	rect temp;
	temp = (rect){max(p->x1, q->x1), max(p->y1, q->y1), min(p->x2, q->x2), min(p->y2, q->y2)};
	return valid(&temp);
}

void split(rect *p, rect *q)
{
	rect temp;
	temp = (rect){p->x1, max(p->y1, q->y1), q->x1, min(p->y2, q->y2)};
	if(valid(&temp))
	{
		ary[m++] = temp;
	}
	temp = (rect){q->x2, max(p->y1, q->y1), p->x2, min(p->y2, q->y2)};
	if(valid(&temp))
	{
		ary[m++] = temp;
	}
	temp = (rect){p->x1, p->y1, p->x2, q->y1};
	if(valid(&temp))
	{
		ary[m++] = temp;
	}
	temp = (rect){p->x1, q->y2, p->x2, p->y2};
	if(valid(&temp))
	{
		ary[m++] = temp;
	}
}

double getarea(rect *p)
{
	return (p->x2-p->x1) * (p->y2-p->y1);
}

int main()
{
	int cas, n, i, j;
	double a, b, c, res;
	rect now, temp;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		scanf("%lf%lf%lf", &a, &b, &c);
		ary[0] = (rect){a-c, b-c, a+c, b+c};
		for(i=1, m=1; i<n; i++)
		{
			scanf("%lf%lf%lf", &a, &b, &c);
			now = (rect){a-c, b-c, a+c, b+c};
			for(j=m-1; j>=0; j--)
			{
				if(intersect(&now, &ary[j]))
				{
					temp = ary[j];
					ary[j] = ary[--m];
					split(&temp, &now);
				}
			}
			ary[m++] = now;
		}
		for(i=0, res=0; i<m; i++)
		{
			res += getarea(&ary[i]);
		}
		printf("%d %.2lf\n", ++cas, res);
	}
	return 0;
}

