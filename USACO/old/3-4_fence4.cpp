/*
	ID: sa072682
	LANG: C
	TASK: fence4
*/
#include <stdio.h>
#include <stdlib.h>

double point[201][2], s[2];
int pair[201][2], n;

int comp(const void *p, const void *q)
{
	if(((int*)p)[1] == ((int*)q)[1])
	{
		return ((int*)p)[0] - ((int*)q)[0];
	}
	return ((int*)p)[1] - ((int*)q)[1];
}

double cross(double x1, double y1, double x2, double y2)
{
	return x1 * y2 - x2 * y1;
}

double ab(double now)
{
	if(now < 0)
	{
		return -now;
	}
	return now;
}

int lcomp(double* a, double* b, double* c, double* d)
{
	return ab((a[0]-b[0])*(c[1]-d[1])-(a[1]-b[1])*(c[0]-d[0])) < 0.1;
}

double min(double p, double q)
{
	if(p < q)
	{
		return p;
	}
	return q;
}

double max(double p, double q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

int intersect(double* a, double* b, double* c, double* d)
{
	if(cross(a[0]-c[0], a[1]-c[1], d[0]-c[0], d[1]-c[1]) * cross(b[0]-c[0], b[1]-c[1], d[0]-c[0], d[1]-c[1]) <= 0)
	{
		if(cross(c[0]-a[0], c[1]-a[1], b[0]-a[0], b[1]-a[1]) * cross(d[0]-a[0], d[1]-a[1], b[0]-a[0], b[1]-a[1]) <= 0)
		{
			if(lcomp(a, b, c, d))
			{
				return min(a[0], b[0]) <= max(c[0], d[0]) && max(a[0], b[0]) >= min(c[0], d[0]) && min(a[1], b[1]) <= max(c[1], d[1]) && max(a[1], b[1]) >= min(c[1], d[1]);
			}
			return 1;
		}
	}
	return 0;
}

int pcomp(double* p, double* q)
{
	return ab(p[0] - q[0]) < 0.015 && ab(p[1] - q[1]) < 0.015;
}

int visible(double* p, double* q, int a, int b)
{
	double c[2], d[2], e[2];
	int i, il, ir;
	if(pcomp(p, q))
	{
		return 0;
	}
	c[0] = p[0] + q[0];
	c[1] = p[1] + q[1];
	c[0] /= 2;
	c[1] /= 2;
	d[0] = c[0] - 0.0000001;
	d[1] = c[1] - 0.0000001;
	e[0] = c[0] + 0.0000001;
	e[1] = c[1] + 0.0000001;
	for(i=1; i<n; i++)
	{
		if((a != i-1 || b != i) && intersect(s, c, point[i], point[i-1]))
		{
			il = intersect(s, p, point[i], point[i-1]) && intersect(s, c, point[i], point[i-1]);
			ir = intersect(s, c, point[i], point[i-1]) && intersect(s, q, point[i], point[i-1]);
			if(il && ir)
			{
				return 0;
			}
			else if(!il && !ir)
			{
				return visible(p, d, a, b) || visible(e, q, a, b);
			}
			else if(il)
			{
				return visible(e, q, a, b);
			}
			else
			{
				return visible(p, d, a, b);
			}
		}
	}
	if((a != 0 || b != n-1) && intersect(s, c, point[0], point[n-1]))
	{
		il = intersect(s, p, point[0], point[n-1]) && intersect(s, c, point[0], point[n-1]);
		ir = intersect(s, c, point[0], point[n-1]) && intersect(s, q, point[0], point[n-1]);
		if(il && ir)
		{
			return 0;
		}
		else if(!il && !ir)
		{
			return visible(p, d, a, b) || visible(e, q, a, b);
		}
		else if(il)
		{
			return visible(e, q, a, b);
		}
		else
		{
			return visible(p, d, a, b);
		}
	}
	return 1;
}

int main()
{
	int i, j, k;
	freopen("fence4.in", "r", stdin);
	freopen("fence4.out", "w", stdout);
	scanf("%d%lf%lf", &n, &s[0], &s[1]);
	for(i=0; i<n; i++)
	{
		scanf("%lf%lf", &point[i][0], &point[i][1]);
		for(j=1; j<i-1; j++)
		{
			if(intersect(point[i], point[i-1], point[j], point[j-1]))
			{
				break;
			}
		}
		if(j < i-1)
		{
			break;
		}
	}
	if(i < n)
	{
		printf("NOFENCE\n");
	}
	else
	{
		for(i=1, k=0; i<n; i++)
		{
			if(visible(point[i-1], point[i], i-1, i))
			{
				pair[k][0] = i-1;
				pair[k++][1] = i;
			}
		}
		if(visible(point[0], point[n-1], 0, n-1))
		{
			pair[k][0] = 0;
			pair[k++][1] = n-1;
		}
		qsort(pair, k, sizeof(pair[0]), comp);
		printf("%d\n", k);
		for(i=0; i<k; i++)
		{
			printf("%.0lf %.0lf %.0lf %.0lf\n", point[pair[i][0]][0], point[pair[i][0]][1], point[pair[i][1]][0], point[pair[i][1]][1]);
		}
	}
	scanf(" ");
	return 0;
}
