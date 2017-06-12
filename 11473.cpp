#include <stdio.h>
#include <math.h>

double px[105], py[105];

double get_dis(double x, double y)
{
	return sqrt(x*x+y*y);
}

int main()
{
	int cas, count, n, m, i, next;
	double sum, avg, ppx, ppy, nx, ny, rdd, dd;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		for(i=0, sum=0; i<n; i++)
		{
			scanf("%lf%lf", &px[i], &py[i]);
			if(i)
			{
				sum += get_dis(px[i]-px[i-1], py[i]-py[i-1]);
			}
		}
		avg = sum / (m-1);
		printf("Road #%d:\n", ++cas);
		printf("%.2lf %.2lf\n", px[0], py[0]);
		for(i=1, ppx=px[0], ppy=py[0], nx=px[1], ny=py[1], next=2; i<m; i++)
		{
			rdd = avg;
			while(1)
			{
				dd = get_dis(ppx-nx, ppy-ny);
				if(dd >= rdd)
				{
					ppx += (nx-ppx) * rdd / dd;
					ppy += (ny-ppy) * rdd / dd;
					printf("%.2lf %.2lf\n", ppx, ppy);
					break;
				}
				else
				{
					rdd -= dd;
					ppx = nx;
					ppy = ny;
					nx = px[next];
					ny = py[next];
					next++;
				}
			}
		}
		printf("\n");
	}
	return 0;
}
