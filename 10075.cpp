#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define INF 1073741823
#define R 6378.0

int index[105], map[105][105];
char name[105][25];
char buf1[2008], buf2[2008];
double latitude[105], longitude[105], PI;

int comp(const void *p, const void *q)
{
	return strcmp(name[*(int*)p], name[*(int*)q]);
}

int bisearch(char *s, int left, int right)
{
	int center, cmp;
	center = left + right;
	center >>= 1;
	cmp = strcmp(s, name[index[center]]);
	if(!cmp)
	{
		return index[center];
	}
	else if(cmp > 0)
	{
		return bisearch(s, center+1, right);
	}
	return bisearch(s, left, center-1);
}

double getlen(double x, double y, double z)
{
	return sqrt(x*x+y*y+z*z);
}

int getdis(int p, int q)
{
	int res;
	char *ptr;
	double a1, a2, b1, b2, x1, x2, y1, y2, z1, z2, d, theta;
	a1 = (latitude[p] * PI) / 180.0;
	a2 = (latitude[q] * PI) / 180.0;
	b1 = (longitude[p] * PI) / 180.0;
	b2 = (longitude[q] * PI) / 180.0;
	x1 = R * cos(a1) * cos(b1);
	y1 = R * cos(a1) * sin(b1);
	z1 = R * sin(a1);
	x2 = R * cos(a2) * cos(b2);
	y2 = R * cos(a2) * sin(b2);
	z2 = R * sin(a2);
	d = getlen(x1-x2, y1-y2, z1-z2);
	theta = acos((R*R*2.0-d*d)/(R*R*2.0));
	sprintf(buf1, "%.0lf", R * theta);
	for(res=0, ptr=buf1; *ptr; res*=10, res+=(*ptr++)-'0');
	return res;
}

int main()
{
	int cas, n, m, o, i, j, k, n1, n2;
	cas = 0;
	PI = 2.0 * acos(0.0);
	while(scanf("%d%d%d", &n, &m, &o) == 3)
	{
		if(!n && !m && !o)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%s%lf%lf", name[i], &latitude[i], &longitude[i]);
			index[i] = i;
		}
		qsort(index, n, sizeof(int), comp);
		for(i=0; i<n; i++)
		{
			for(j=i; j<n; j++)
			{
				map[i][j] = map[j][i] = INF;
			}
		}
		while(m--)
		{
			scanf("%s%s", buf1, buf2);
			n1 = bisearch(buf1, 0, n-1);
			n2 = bisearch(buf2, 0, n-1);
			map[n1][n2] = getdis(n1, n2);
		}
		for(k=0; k<n; k++)
		{
			for(i=0; i<n; i++)
			{
				for(j=0; j<n; j++)
				{
					if(map[i][j] > map[i][k] + map[k][j])
					{
						map[i][j] = map[i][k] + map[k][j];
					}
				}
			}
		}
		if(cas)
		{
			printf("\n");
		}
		printf("Case #%d\n", ++cas);
		while(o--)
		{
			scanf("%s%s", buf1, buf2);
			n1 = bisearch(buf1, 0, n-1);
			n2 = bisearch(buf2, 0, n-1);
			if(map[n1][n2] == INF)
			{
				printf("no route exists\n");
			}
			else
			{
				printf("%d km\n", map[n1][n2]);
			}
		}
	}
	return 0;
}
