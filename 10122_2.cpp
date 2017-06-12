#include <stdio.h>
#include <string.h>
#include <math.h>

#define Infinity 2e3
#define STEP 1e-4
#define EPS 1e-6

int n, lbound, rbound;
double dislim;
int x[105], y[105];
int c[105], w[105], s[105];
int hused[105], mused[105];
int assigned[105];
int ptr[105];
int num[1005];
int conn[1005][105];
double map[1005][105];
double dist[105][105];
/*double tbl[2010000];*/

int zero(double now)
{
	return now < EPS;
}

int ab(int now)
{
	if(now < 0)
	{
		return -now;
	}
	return now;
}

double getdist(int x, int y)
{
	/*int temp;
	temp = x*x + y*y;
	if(tbl[temp])
	{
		return tbl[temp];
	}
	return tbl[temp]=sqrt(x*x+y*y);*/
	return sqrt(x*x+y*y);
}

int cross(int x1, int y1, int x2, int y2)
{
	return x1*y2 - x2*y1;
}

void minbsearch(int left, int right, int target)
{
	int center, i;
	/*int p, q;*/
	if(left > right)
	{
		return;
	}
	center = left + right;
	center /= 2;
	for(i=1; i<target; i++)
	{
		if(x[i] > center)
		{
			break;
		}
	}
	for(; i<target; i++)
	{
		if((long long)cross(x[target]-center, y[target], x[i]-center, y[i]) * cross(x[target]-center, y[target], x[n+1]-center, y[n+1]) > 0)
		{
			break;
		}
		/*p = cross(x[target]-center, y[target], x[i]-center, y[i]);
		q = cross(x[target]-center, y[target], x[n+1]-center, y[n+1]);
		if((p > 0 && q > 0) || (p < 0 && q < 0))
		{
			break;
		}*/
	}
	if(i == target)
	{
		right = center - 1;
		lbound = center;
	}
	else
	{
		left = center + 1;
	}
	minbsearch(left, right, target);
}

void maxbsearch(int left, int right, int target)
{
	int center, i;
	/*int p, q;*/
	if(left > right)
	{
		return;
	}
	center = left + right;
	center /= 2;
	for(i=n; i>target; i--)
	{
		if(x[i] < center)
		{
			break;
		}
	}
	for(; i>target; i--)
	{
		if((long long)cross(x[target]-center, y[target], x[i]-center, y[i]) * cross(x[target]-center, y[target], x[0]-center, y[0]) > 0)
		{
			break;
		}
		/*p = cross(x[target]-center, y[target], x[i]-center, y[i]);
		q = cross(x[target]-center, y[target], x[0]-center, y[0]);
		if((p > 0 && q > 0) || (p < 0 && q < 0))
		{
			break;
		}*/
	}
	if(i == target)
	{
		left = center + 1;
		rbound = center;
	}
	else
	{
		right = center - 1;
	}
	maxbsearch(left, right, target);
}

int fill(int);

int reach(int now)
{
	if(!assigned[now])
	{
		return 1;
	}
	else if(!hused[assigned[now]])
	{
		return fill(assigned[now]);
	}
	return 0;
}

int fill(int now)
{
	int i;
	hused[now] = 1;
	/*for(; ptr[now]<=n; ptr[now]++)
	{
		if(dist[now][ptr[now]] < dislim && !assigned[ptr[now]] && !mused[ptr[now]])
		{
			assigned[ptr[now]] = now;
			return 1;
		}
	}*/
	for(i=1; i<=n; i++)
	{
		if(dist[now][i] < dislim && !assigned[i] && !mused[i])
		{
			assigned[i] = now;
			return 1;
		}
	}
	for(i=1; i<=n; i++)
	{
		if(dist[now][i] < dislim && !mused[i])
		{
			mused[i] = 1;
			if(reach(i))
			{
				assigned[i] = now;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int i, j, k;
	double temp, d, left, right, center, ans;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		for(i=0; i<=n+1; i++)
		{
			scanf("%d%d", &x[i], &y[i]);
		}
		memset(num, 0, sizeof(num));
		for(i=1; i<=n; i++)
		{
			lbound = rbound = x[i];
			minbsearch(x[0], lbound-1, i);
			maxbsearch(rbound+1, x[n+1], i);
			for(j=lbound; j<=rbound; j++)
			{
				map[j][num[j]] = getdist(j-x[i], y[i]);
				/*printf("%.3lf\n", map[j][num[j]]);*/
				conn[j][num[j]++] = i;
			}
			for(j=1; j<=n; j++)
			{
				dist[i][j] = Infinity;
			}
		}
		for(i=1; i<=n; i++)
		{
			scanf("%d%d%d", &c[i], &w[i], &s[i]);
			ptr[i] = 1;
			for(j=x[0]; j<=x[n+1]; j++)
			{
				temp = (double)ab(j-s[i]) / w[i];
				for(k=0; k<num[j]; k++)
				{
					d = temp + map[j][k] / c[i];
					/*printf("%.4lf %.4lf %.4lf\n", temp, map[j][k]/c[i], d);*/
					if(d < dist[i][conn[j][k]])
					{
						dist[i][conn[j][k]] = d;
					}
				}
			}
		}
		/*for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
			{
				printf("dist between %d and %d: %.2lf\n", i, j, dist[i][j]);
			}
		}*/
		for(left=0, right=Infinity; left<right&&!zero(right-left); )
		{
			center = left + right;
			center /= 2;
			/*printf("%.4lf\n", center);*/
			memset(assigned, 0, sizeof(assigned));
			for(i=1, dislim=center; i<=n; i++)
			{
				memset(hused, 0, sizeof(hused));
				memset(mused, 0, sizeof(mused));
				if(!fill(i))
				{
					break;
				}
			}
			if(i > n)
			{
				ans = center;
				right = center - STEP;
			}
			else
			{
				left = center + STEP;
			}
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}
