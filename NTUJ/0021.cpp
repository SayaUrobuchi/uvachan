#include <stdio.h>
#include <stdlib.h>

typedef struct point
{
	int x, y;
	int id;
	int used;
}point;

point pitem[3005];
point* plist[3005];
int stack[3005];

int p_comp(const void *a, const void *b)
{
	point *p, *q;
	p = *(point**)a;
	q = *(point**)b;
	return p->y == q->y ? p->x - q->x : p->y - q->y;
}

int cross(int a, int b, int c, int d)
{
	return a*d - b*c;
}

int main()
{
	int n, i, m, t, id;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%d", &id);
			scanf("%d%d", &pitem[id].x, &pitem[id].y);
			pitem[id].used = 0;
			pitem[id].id = id;
			plist[i] = &pitem[id];
		}
		qsort(plist, n, sizeof(point*), p_comp);
		m = 0;
		while(m<n)
		{
			for(i=0; i<n; i++)
			{
				if(plist[i]->used == 0)
				{
					while(m>=2&&cross(pitem[stack[m-1]].x-pitem[stack[m-2]].x, 
						pitem[stack[m-1]].y-pitem[stack[m-2]].y, 
						plist[i]->x-pitem[stack[m-2]].x, 
						plist[i]->y-pitem[stack[m-2]].y) < 0)
					{
						m--;
						pitem[stack[m]].used = 0;
					}
					stack[m++] = plist[i]->id;
					plist[i]->used = 1;
				}
			}
			for(i=n-1, t=m; i>=0; i--)
			{
				if(plist[i]->used == 0)
				{
					while(m>t&&cross(pitem[stack[m-1]].x-pitem[stack[m-2]].x, 
						pitem[stack[m-1]].y-pitem[stack[m-2]].y, 
						plist[i]->x-pitem[stack[m-2]].x, 
						plist[i]->y-pitem[stack[m-2]].y) < 0)
					{
						m--;
						pitem[stack[m]].used = 0;
					}
					stack[m++] = plist[i]->id;
					plist[i]->used = 1;
				}
			}
		}
		printf("%d", n);
		for(i=0; i<n; i++)
		{
			printf(" %d", stack[i]);
		}
		printf("\n");
	}
	return 0;
}
