#include <stdio.h>
#include <string.h>
#include <math.h>

int dis[10005], px[10005], py[10005];
char used[10005];

int getdis(int p, int q)
{
	return p*p+q*q;
}

int main()
{
	int n, i, j, temp, min, dtemp;
	double ans;
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &px[i], &py[i]);
		}
		for(i=1; i<n; i++)
		{
			dis[i] = getdis(px[i]-px[0], py[i]-py[0]);
		}
		memset(used, 0, sizeof(used));
		used[0] = 1;
		for(i=1, ans=0.0; i<n; i++)
		{
			for(j=1, min=2147483647; j<n; j++)
			{
				if(used[j] == 0 && dis[j] < min)
				{
					min = dis[j];
					temp = j;
				}
			}
			used[temp] = 1;
			ans += sqrt(min);
			for(j=1; j<n; j++)
			{
				if(used[j] == 0 && (dtemp=getdis(px[j]-px[temp], py[j]-py[temp])) < dis[j])
				{
					dis[j] = dtemp;
				}
			}
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}
