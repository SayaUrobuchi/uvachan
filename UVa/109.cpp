#include <stdio.h>
#include <stdlib.h>

int num[25];
char dead[25];

struct point
{
	int x, y;
};

struct point p[105], ch[25][105];

int comp(const void *p, const void *q)
{
	if(((struct point*)p)->x != ((struct point*)q)->x)
	{
		return ((struct point*)p)->x - ((struct point*)q)->x;
	}
	return ((struct point*)p)->y - ((struct point*)q)->y;
}

int cross(struct point p, struct point q, struct point r)
{
	return (q.x-p.x) * (r.y-p.y) - (q.y-p.y) * (r.x-p.x);
}

int main()
{
	int n, m, o, t, i, j;
	double a, area;
	struct point missile;
	n = 0;
	while(scanf("%d", &m) == 1)
	{
		if(m == -1)
		{
			break;
		}
		num[n] = 0;
		for(i=0; i<m; i++)
		{
			scanf("%d%d", &p[i].x, &p[i].y);
		}
		qsort(p, m, sizeof(struct point), comp);
		t = m;
		m = 0;
		for(i=0; i<t; i++)
		{
			for(; m>=2&&cross(ch[n][m-2], ch[n][m-1], p[i])<=0; m--);
			ch[n][m++] = p[i];
		}
		o = m + 1;
		for(i-=2; i>=0; i--)
		{
			for(; m>=o&&cross(ch[n][m-2], ch[n][m-1], p[i])<=0; m--);
			ch[n][m++] = p[i];
		}
		/*printf("\n");
		for(i=0; i<m; i++)
		{
			printf("%d %d\n", ch[n][i].x, ch[n][i].y);
		}
		printf("\n");*/
		num[n++] = m;
	}
	area = 0.0;
	while(scanf("%d%d", &missile.x, &missile.y) == 2)
	{
		for(i=0; i<n; i++)
		{
			if(!dead[i])
			{
				for(j=1; j<num[i]; j++)
				{
					if(cross(ch[i][j-1], ch[i][j], missile) <= 0)
					{
						break;
					}
				}
				if(j == num[i])
				{
					dead[i] = 1;
					for(j=2, a=0; j<num[i]; j++)
					{
						a += cross(ch[i][0], ch[i][j-1], ch[i][j]);
					}
					area += a / 2.0;
				}
			}
		}
	}
	printf("%.2lf\n", area);
	/*for(; ; );*/
	return 0;
}
