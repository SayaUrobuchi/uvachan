#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INF 1e30

struct point
{
	double x, y;
};

struct point p[1005], ch[3005], o;

int comp(const void *p, const void *q)
{
	if(((struct point*)p)->x != ((struct point*)q)->x)
	{
		if(((struct point*)p)->x > ((struct point*)q)->x)
		{
			return 1;
		}
		return -1;
	}
	if(((struct point*)p)->y > ((struct point*)q)->y)
	{
		return 1;
	}
	return -1;
}

double getdist(double x, double y)
{
	return sqrt(x*x+y*y);
}

double cross(struct point p, struct point q, struct point r)
{
	return (q.x-p.x) * (r.y-p.y) - (q.y-r.y) * (r.x-p.x);
}

int main()
{
	int count, n, m, i, j, k;
	double len, ml, ans, tl, ul;
	o.x = o.y = 0;
	 freopen("1.txt", "w", stdout); 
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%lf%lf", &p[i].x, &p[i].y);
		}
		p[n++] = o;
		qsort(p, n, sizeof(struct point), comp);
		/* try every point directly connected to o */
		ans = -1;
		for (k=0; k<n; k++)
		{
			m = 0;
			ch[m++] = o;
			ch[m++] = p[k];
			if (p[k].y > 0)
			{
				for(i=k-1; i>=0; i--)
				{
					for(; m>=2&&cross(ch[m-2], ch[m-1], p[i])<=0; m--);
					ch[m++] = p[i];
				}
				for(i=1, j=m+1; i<n; i++)
				{
					for(; m>=j&&cross(ch[m-2], ch[m-1], p[i])<=0; m--);
					ch[m++] = p[i];
				}
				for (i=n-2, j=m+1; i>k; i--)
				{
					for(; m>=j&&cross(ch[m-2], ch[m-1], p[i])<=0; m--);
					ch[m++] = p[i];
				}
			}
			else
			{
				for(i=k+1; i<n; i++)
				{
					for(; m>=2&&cross(ch[m-2], ch[m-1], p[i])<=0; m--);
					ch[m++] = p[i];
				}
				for(i=n-2, j=m+1; i>=0; i--)
				{
					for(; m>=j&&cross(ch[m-2], ch[m-1], p[i])<=0; m--);
					ch[m++] = p[i];
				}
				for (i=0, j=m+1; i<k; i++)
				{
					for(; m>=j&&cross(ch[m-2], ch[m-1], p[i])<=0; m--);
					ch[m++] = p[i];
				}
			}
			ch[m++] = o;
			for(i=1, len=2.0; i<m; i++)
			{
				len += getdist(ch[i-1].x-ch[i].x, ch[i-1].y-ch[i].y);
			}
			if (ans < 0 || len < ans)
			{
				ans = len;
			}
		}
		printf("%.2lf\n", ans);
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
