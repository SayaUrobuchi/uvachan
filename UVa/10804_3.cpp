#include <stdio.h>
#include <string.h>
#include <math.h>

#define Infinity 1e5
#define EPS 1e-8
#define STEP 1e-5

int n, m, o;
double dislim;
int holed[60];
int lived[60];
int gused[60];
int hused[60];
double x[110], y[110];
double map[60][60];

int zero(double now)
{
	return now < EPS;
}

double getdist(double xcoor, double ycoor)
{
	return sqrt(xcoor * xcoor + ycoor * ycoor);
}

int fill(int);

int enter(int now)
{
	if(!lived[now])
	{
		return 1;
	}
	else if(!gused[lived[now]-1])
	{
		return fill(lived[now]-1);
	}
	else
	{
		return 0;
	}
}

int fill(int now)
{
	int i;
	gused[now] = 1;
	for(i=0; i<m; i++)
	{
		if(map[now][i] < dislim && !hused[i] && !lived[i])
		{
			lived[i] = now + 1;
			hused[i] = 0;
			gused[now] = 0;
			return 1;
		}
	}
	for(i=0; i<m; i++)
	{
		if(map[now][i] < dislim && !hused[i])
		{
			hused[i] = 1;
			if(enter(i))
			{
				lived[i] = now + 1;
				hused[i] = 0;
				gused[now] = 0;
				return 1;
			}
			hused[i] = 0;
		}
	}
	gused[i] = 0;
	return 0;
}

int main()
{
	int cas, count, i, j, c;
	double left, right, center, ans;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d", &n, &m, &o);
		for(i=0; i<n; i++)
		{
			scanf("%lf%lf", &x[i], &y[i]);
		}
		for(i=0; i<m; i++)
		{
			scanf("%lf%lf", &x[i+n], &y[i+n]);
			for(j=0; j<n; j++)
			{
				map[j][i] = getdist(x[j]-x[i+n], y[j]-y[i+n]);
				/*printf("%d->%d: %.3lf\n", j, i, map[j][i]);*/
			}
		}
		for(left=0.0, right=Infinity, ans=-1; left<right&&!zero(right-left); )
		{
			/*printf("l: %.3lf, r: %.3lf\n", left, right);*/
			center = left + right;
			center /= 2;
			memset(lived, 0, sizeof(lived));
			/*printf("%.3lf\n", center);*/
			for(i=0, c=0, dislim=center; i<n; i++)
			{
				/*memset(gused, 0, sizeof(gused));
				memset(hused, 0, sizeof(hused));*/
				c += fill(i);
				if(c == n-o)
				{
					break;
				}
			}
			if(i == n)
			{
				left = center + STEP;
			}
			else
			{
				ans = center;
				right = center - STEP;
			}
		}
		if(ans < 0)
		{
			printf("Case #%d:\nToo bad.\n\n", ++cas);
		}
		else
		{
			printf("Case #%d:\n%.3lf\n\n", ++cas, ans);
		}
	}
	return 0;
}
