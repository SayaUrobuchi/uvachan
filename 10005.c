#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct point
{
	double x, y;
}point;

int comp(const void *p, const void *q)
{
	point *i, *j;
	i = *(point**)p;
	j = *(point**)q;
	return i->x == j->x ? (i->y < j->y ? -1 : 1) : (i->x < j->x ? -1 : 1);
}

int equal(double p, double q)
{
	return fabs(p-q) < 1e-10;
}

double getdis(point *p, point *q)
{
	double x, y;
	x = p->x - q->x;
	y = p->y - q->y;
	return sqrt(x*x+y*y);
}

point get_vector(point *p, point *q)
{
	return (point){q->x-p->x, q->y-p->y};
}

double cross(point p, point q)
{
	return p.x*q.y - p.y*q.x;
}

void convex_hull(point *ary[], int n, point *chull[], int *m)
{
	int i, t;
	qsort(ary, n, sizeof(point*), comp);
	for(i=0, *m=0; i<n; i++)
	{
		while(*m>=2&&cross(get_vector(ary[i], chull[*m-1]), get_vector(ary[i], chull[*m-2])) < 0)
		{
			(*m)--;
		}
		chull[(*m)++] = ary[i];
	}
	for(i=n-2, t=*m; i>=0; i--)
	{
		while(*m>=t&&cross(get_vector(ary[i], chull[*m-1]), get_vector(ary[i], chull[*m-2])) < 0)
		{
			(*m)--;
		}
		chull[(*m)++] = ary[i];
	}
}

point rev_vector(point p)
{
	return (point){p.y, -p.x};
}

point get_middle(point *p, point *q)
{
	return (point){(p->x+q->x)/2, (p->y+q->y)/2};
}

point add_vector(point p, point q)
{
	return (point){p.x+q.x, p.y+q.y};
}

point get_point(point *a, point *b, point *c)
{
	point v1, v2, p1, p2, p3, p4;
	double c1, c2;
	v1 = rev_vector(get_vector(a, b));
	v2 = rev_vector(get_vector(b, c));
	p1 = get_middle(a, b);
	p2 = add_vector(p1, v1);
	p3 = get_middle(b, c);
	p4 = add_vector(p3, v2);
	c1 = cross(get_vector(&p1, &p2), get_vector(&p3, &p4));
	c2 = cross(get_vector(&p1, &p3), get_vector(&p3, &p4));
	if(equal(c1, 0.0))
	{
		return get_middle(a, c);
	}
	else
	{
		return add_vector(p1, (point){v1.x*c2/c1, v1.y*c2/c1});
	}
}

int check_in_circle(point *ptr[], int n, point p, double r)
{
	int i;
	for(i=0; i<n; i++)
	{
		if(getdis(&p, ptr[i]) > r)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int n, m, i, j;
	double r, d;
	point ary[105], *chull[210], *ptr[105], p;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%lf%lf", &ary[i].x, &ary[i].y);
			ptr[i] = &ary[i];
		}
		scanf("%lf", &r);
		if(n == 1)
		{
			printf("The polygon can be packed in the circle.\n");
		}
		else if(n == 2)
		{
			d = getdis(&ary[0], &ary[1]);
			if(d <= 2*r || equal(d, 2*r))
			{
				printf("The polygon can be packed in the circle.\n");
			}
			else
			{
				printf("There is no way of packing that polygon.\n");
			}
		}
		else
		{
			convex_hull(ptr, n, chull, &m);
			m--;
			for(i=1; i<m; i++)
			{
				for(j=i; j<m; j++)
				{
					p = get_point(chull[0], chull[i], chull[j]);
					if(check_in_circle(ptr, n, p, r))
					{
						break;
					}
				}
				if(j < m)
				{
					break;
				}
			}
			if(i < m)
			{
				printf("The polygon can be packed in the circle.\n");
			}
			else
			{
				printf("There is no way of packing that polygon.\n");
			}
		}
	}
	return 0;
}

