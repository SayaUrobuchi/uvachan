#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define R 6378

double pi;
int index[110];
char name[110][35];
char n1[35], n2[35];
double wei[110];
double gin[110];

struct data
{
	int num;
	double x, y, z;
};

struct data loc1, loc2;

int comp(const void *p, const void *q)
{
	return strcmp(name[*(int*)p], name[*(int*)q]);
}

double getdis(double x, double y, double z)
{
	return sqrt(x*x+y*y+z*z);
}

struct data getcoor(struct data now)
{
	double w, g, r, angle;
	w = wei[now.num];
	g = gin[now.num];
	angle = w * pi / 180;
	now.z = R * sin(angle);
	r = R * cos(angle);
	angle = g * pi / 180;
	now.x = r * sin(angle);
	now.y = r * cos(angle);
	return now;
}

int bisearch(int left, int right, char *target)
{
	int center, cmp;
	if(left > right)
	{
		return -1;
	}
	center = left + right;
	center /= 2;
	cmp = strcmp(name[index[center]], target);
	if(!cmp)
	{
		return index[center];
	}
	else if(cmp > 0)
	{
		return bisearch(left, center-1, target);
	}
	return bisearch(center+1, right, target);
}

int main()
{
	int n;
	double a, cost, ans;
	n = 0;
	pi = 2.0 * acos(0.0);
	while(scanf("%s", name[n]) == 1)
	{
		if(!strcmp(name[n], "#"))
		{
			break;
		}
		scanf("%lf%lf", &wei[n], &gin[n]);
		index[n] = n;
		n++;
	}
	qsort(index, n, sizeof(int), comp);
	while(scanf("%s%s", n1, n2) == 2)
	{
		if(!strcmp(n1, "#") && !strcmp(n2, "#"))
		{
			break;
		}
		printf("%s - %s\n", n1, n2);
		loc1.num = bisearch(0, n-1, n1);
		loc2.num = bisearch(0, n-1, n2);
		if(loc1.num == -1 || loc2.num == -1)
		{
			printf("Unknown\n");
		}
		else
		{
			loc1 = getcoor(loc1);
			loc2 = getcoor(loc2);
			/*printf("loc %lf %lf %lf\n", loc1.x, loc1.y, loc1.z);
			printf("loc %lf %lf %lf\n", loc2.x, loc2.y, loc2.z);*/
			a = getdis(loc1.x-loc2.x, loc1.y-loc2.y, loc1.z-loc2.z);
			/*printf("dist %lf\n", a);*/
			cost = (R*R*2-a*a)/(2*R*R);
			/*printf("cos %lf\n", cost);
			printf("acos %lf\n", acos(cost));*/
			ans = R * acos(cost);
			printf("%.0lf km\n", ans);
		}
	}
	return 0;
}
