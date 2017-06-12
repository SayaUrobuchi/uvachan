#include <stdio.h>
#include <stdlib.h>

typedef struct point
{
	int x, y, z;
}point;

point p[100005], ans[100005];

int comp(const void *p, const void *q)
{
	point a, b;
	a = *(point*)p;
	b = *(point*)q;
	if(a.x * b.y != a.y * b.x)
	{
		return a.x*b.y - a.y*b.x;
	}
	if(a.x == b.x)
	{
		return a.y - b.y;
	}
	if((long long)a.x * b.x < 0)
	{
		return a.x - b.x;
	}
	return abs(a.x) - abs(b.x);
}

int comp2(const void *p, const void *q)
{
	point a, b;
	a = *(point*)p;
	b = *(point*)q;
	if(a.x != b.x)
	{
		return a.x - b.x;
	}
	return a.y - b.y;
}

int visible(point p, point q)
{
	if(p.x * q.y != p.y * q.x)
	{
		return 1;
	}
	if((long long)p.x * q.x < 0)
	{
		return 1;
	}
	return p.z < q.z;
}

int main()
{
	int cas, n, m, i, j;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].z);
		}
		qsort(p, n, sizeof(point), comp);
		for(i=0, m=0; i<n; i++)
		{
			for(j=i-1; j>=0; j--)
			{
				if(p[j].x * p[i].y != p[j].y * p[i].x)
				{
					break;
				}
				if(visible(p[j], p[i]) == 0)
				{
					ans[m++] = p[i];
					break;
				}
			}
		}
		qsort(ans, m, sizeof(point), comp2);
		printf("Data set %d:\n", ++cas);
		if(m == 0)
		{
			printf("All the lights are visible.\n");
		}
		else
		{
			printf("Some lights are not visible:\n");
			for(i=0; i<m; i++)
			{
				printf("x = %d, y = %d%c\n", ans[i].x, ans[i].y, i==m-1?'.':';');
			}
		}
	}
	return 0;
}
