#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INF 1e30

struct point
{
	double x, y;
};

struct point p[1005], ch[2005], o;

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
	double len, ans;
	o.x = o.y = 0;
	freopen("1.txt", "w", stdout);
	scanf("%d", &count);
	while(count--)
	{
		printf("COUNT %d\n", count);
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%lf%lf", &p[i].x, &p[i].y);
		}
		p[n++] = o;
		qsort(p, n, sizeof(struct point), comp);
		for(i=0, m=0; i<n; i++)
		{
			for(; m>=2&&cross(ch[m-2], ch[m-1], p[i])<=0; m--);
			ch[m++] = p[i];
		}
		for(i=n-2, j=m+1; i>=0; i--)
		{
			for(; m>=j&&cross(ch[m-2], ch[m-1], p[i])<=0; m--);
			ch[m++] = p[i];
		}
		for(i=0; i<m; i++)
		{
			if(ch[i].x == o.x && ch[i].y == o.y)
			{
				break;
			}
		}
		if(i == m)
		{
			for(k=0, ans=INF; k<n; k++)
			{
				for(i=0, m=0; i<k; i++)
				{
					for(; m>=2&&cross(ch[m-2], ch[m-1], p[i])<=0; m--);
					ch[m++] = p[i];
				}
				for(; m>=2&&cross(ch[m-2], ch[m-1], p[i])<=0; m--);
				ch[m++] = o;
				for(j=m+1; i<n; i++)
				{
					for(; m>=j&&cross(ch[m-2], ch[m-1], p[i])<=0; m--);
					ch[m++] = p[i];
				}
				for(i=n-2, j=m+1; i>=0; i--)
				{
					for(; m>=j&&cross(ch[m-2], ch[m-1], p[i])<=0; m--);
					ch[m++] = p[i];
				}
				if(k == 0)
				{
					ch[m++] = o;
				}
				printf("CONVEX HULL START!!\n");
				for(i=0; i<m; i++)
				{
					printf("%.2lf %.2lf\n", ch[i].x, ch[i].y);
				}
				printf("CONVEX HULL END!!\n");
				for(i=1, len=2.0; i<m; i++)
				{
					len += getdist(ch[i-1].x-ch[i].x, ch[i-1].y-ch[i].y);
				}
				printf("TOTAL LEN: %.2lf\n", len);
				if(len < ans)
				{
					ans = len;
				}
				/* separate line */
				m = 0;
				if(k == 0)
				{
					ch[m++] = o;
				}
				for(i=0; i<n; i++)
				{
					for(; m>=2&&cross(ch[m-2], ch[m-1], p[i])<=0; m--);
					ch[m++] = p[i];
				}
				for(i=n-2, j=m+1; i>=k; i--)
				{
					for(; m>=j&&cross(ch[m-2], ch[m-1], p[i])<=0; m--);
					ch[m++] = p[i];
				}
				for(; m>=j&&cross(ch[m-2], ch[m-1], p[i])<=0; m--);
				ch[m++] = o;
				for(j=m+1; i>=0; i--)
				{
					for(; m>=j&&cross(ch[m-2], ch[m-1], p[i])<=0; m--);
					ch[m++] = p[i];
				}
				printf("CONVEX HULL START!!\n");
				for(i=0; i<m; i++)
				{
					printf("%.2lf %.2lf\n", ch[i].x, ch[i].y);
				}
				printf("CONVEX HULL END!!\n");
				for(i=1, len=2.0; i<m; i++)
				{
					len += getdist(ch[i-1].x-ch[i].x, ch[i-1].y-ch[i].y);
				}
				printf("TOTAL LEN: %.2lf\n", len);
				if(len < ans)
				{
					ans = len;
				}
			}
		}
		else
		{
			for(i=1, len=2.0, ans=INF; i<m; i++)
			{
				len += getdist(ch[i-1].x-ch[i].x, ch[i-1].y-ch[i].y);
			}
			if(len < ans)
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
