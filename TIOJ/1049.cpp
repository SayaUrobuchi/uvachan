#include <stdio.h>
#include <stdlib.h>

int int_n, id[105];
double x1[105], x2[105], y1[105], y2[105], int_x[10500], int_y[10500];

double fabs(double p)
{
	return p>0 ? p : -p;
}

int comp(const void *p, const void *q)
{
	double c;
	if(int_x[*(int*)p] != int_x[*(int*)q])
	{
		c = int_x[*(int*)p] - int_x[*(int*)q];
	}
	else
	{
		c = int_y[*(int*)p] - int_x[*(int*)q];
	}
	return c>0 ? 1 : -1;
}

double cross(double x1, double y1, double x2, double y2)
{
	return x1*y2 - x2*y1;
}

int intersect(double x11, double y11, double x12, double y12, double x21, double y21, double x22, double y22, double *x, double *y)
{
	if(cross(x12-x11, y12-y11, x21-x11, y21-y11) * cross(x12-x11, y12-y11, x22-x11, y22-y11) < 0 &&
			cross(x22-x21, y22-y21, x11-x21, y11-y21) * cross(x22-x21, y22-y21, x12-x21, y12-y21) < 0)
	{
		*x = x11 + (x12-x11) * cross(x21-x11, y21-y11, x22-x21, y22-y21) / cross(x12-x11, y12-y11, x22-x21, y22-y21);
		*y = y11 + (y12-y11) * cross(x21-x11, y21-y11, x22-x21, y22-y21) / cross(x12-x11, y12-y11, x22-x21, y22-y21);
		return 1;
	}
	return 0;
}

void add_intersection(double x, double y)
{
	id[int_n] = int_n;
	int_x[int_n] = x;
	int_y[int_n] = y;
	int_n++;
}

int same(double x1, double y1, double x2, double y2)
{
	return fabs(x1-x2) < 1e-7 && fabs(y1-y2) < 1e-7;
}

int count_intersection()
{
	int i, j, c;
	qsort(id, int_n, sizeof(int), comp);
	for(i=0, c=0; i<int_n; i=j)
	{
		for(j=i+1; j<int_n; j++)
		{
			if(same(int_x[id[i]], int_y[id[i]], int_x[id[j]], int_y[id[j]]) == 0)
			{
				break;
			}
		}
		c++;
	}
	return c;
}

int main()
{
	int n, i, j, area;
	double x, y;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		for(i=0, area=n+1; i<n; i++)
		{
			scanf("%lf%lf%lf%lf", &x1[i], &y1[i], &x2[i], &y2[i]);
			for(j=0, int_n=0; j<i; j++)
			{
				if(intersect(x1[i], y1[i], x2[i], y2[i], x1[j], y1[j], x2[j], y2[j], &x, &y))
				{
					add_intersection(x, y);
				}
			}
			area += count_intersection();
		}
		printf("%d\n", area);
	}
	return 0;
}
