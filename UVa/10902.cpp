#include <stdio.h>
#include <string.h>

#define N 100005

int ary[N];
char dead[N];
double px1[N], px2[N], py1[N], py2[N];

struct vector
{
	double x, y;
};

double cross(struct vector p, struct vector q)
{
	return p.x * q.y - p.y * q.x;
}

int intersect(int p, int q)
{
	struct vector v1, v2, v3, v4, v5, v6;
	v1.x = px2[p] - px1[p];
	v1.y = py2[p] - py1[p];
	v2.x = px1[q] - px1[p];
	v2.y = py1[q] - py1[p];
	v3.x = px2[q] - px1[p];
	v3.y = py2[q] - py1[p];
	v4.x = px2[q] - px1[q];
	v4.y = py2[q] - py1[q];
	v5.x = px1[p] - px1[q];
	v5.y = py1[p] - py1[q];
	v6.x = px2[p] - px1[q];
	v6.y = py2[p] - py1[q];
	return cross(v1, v2) * cross(v1, v3) < 0 && cross(v4, v5) * cross(v4, v6) < 0;
}

int main()
{
	int n, i, j, k;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%lf%lf%lf%lf", &px1[i], &py1[i], &px2[i], &py2[i]);
		}
		memset(dead, 0, sizeof(dead));
		for(i=n-1, k=0; i>=0; i--)
		{
			if(!dead[i])
			{
				ary[k++] = i+1;
			}
			for(j=0; j<i; j++)
			{
				if(!dead[j])
				{
					if(intersect(i, j))
					{
						dead[j] = 1;
					}
				}
			}
		}
		printf("Top sticks:");
		for(i=k-1; i>=0; i--)
		{
			if(i == 0)
			{
				printf(" %d.\n", ary[i]);
			}
			else
			{
				printf(" %d,", ary[i]);
			}
		}
	}
	return 0;
}
