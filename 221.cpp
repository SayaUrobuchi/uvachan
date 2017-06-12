#include <stdio.h>
#include <stdlib.h>

int n, list[101];

struct data
{
	int orig;
	double x, y, w, d, h;
};

struct data ary[101];

int comp(const void *p, const void *q)
{
	double xdiff, ydiff;
	xdiff = (*(struct data*)p).x - (*(struct data*)q).x;
	ydiff = (*(struct data*)p).y - (*(struct data*)q).y;
	if(xdiff < 0)
	{
		return -1;
	}
	else if(xdiff == 0)
	{
		if(ydiff < 0)
		{
			return -1;
		}
		else if(ydiff == 0)
		{
			return 0;
		}
		return 1;
	}
	else
	{
		return 1;
	}
}

int ncomp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int visible(int now, double left, double right)
{
	int i;
	double center;
	center = left + right;
	center /= 2.0;
	for(i=0; i<n; i++)
	{
		if(i != now && ary[i].h >= ary[now].h)
		{
			/*if(ary[now].orig == 5) printf("X: %lf %lf, %lf %lf %d %d\n", ary[i].x, ary[i].x+ary[i].w, ary[i].h, ary[now].h, now, i);*/
			if(ary[i].y < ary[now].y && center >= ary[i].x && center <= ary[i].x + ary[i].w)
			{
				if(ary[i].x <= left && ary[i].x + ary[i].w >= right)
				{
					return 0;
				}
				else
				{
					if(right - left < 1e-5)
					{
						return 0;
					}
					else
					{
						return visible(now, left, center-1e-5) || visible(now, center+1e-5, right);
					}
				}
			}
		}
	}
	return 1;
}

int main()
{
	int cas, i, c;
	struct data temp;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%lf%lf%lf%lf%lf", &temp.x, &temp.y, &temp.w, &temp.d, &temp.h);
			ary[i] = temp;
			ary[i].orig = i+1;
		}
		qsort(ary, n, sizeof(struct data), comp);
		for(i=0, c=0; i<n; i++)
		{
			if(visible(i, ary[i].x, ary[i].x+ary[i].w))
			{
				list[c++] = ary[i].orig;
			}
		}
		if(cas)
		{
			printf("\n");
		}
		printf("For map #%d, the visible buildings are numbered as follows:\n", ++cas);
		printf("%d", list[0]);
		for(i=1; i<c; i++)
		{
			printf(" %d", list[i]);
		}
		printf("\n");
	}
	return 0;
}
