#include <stdio.h>
#include <string.h>
#include <math.h>

int dis[100005], px[100005], py[100005], next[100005];
char used[100005];

int getdis(int p, int q)
{
	return p*p+q*q;
}

int main()
{
	int n, i, j, k, t, temp, min, dtemp;
	double ans;
	while(scanf("%d", &n) == 1)
	{
		for(i=1; i<=n; i++)
		{
			scanf("%d%d", &px[i], &py[i]);
			next[i-1] = i;
		}
		next[i-1] = 0;
		for(i=2; i<=n; i++)
		{
			dis[i] = getdis(px[i]-px[1], py[i]-py[1]);
		}
		next[0] = 2;
		for(i=1, ans=0.0; i<n; i++)
		{
			for(j=0, min=2147483647; k=next[j]; j=k)
			{
				if(dis[k] < min)
				{
					min = dis[k];
					temp = j;
				}
			}
			t = next[temp];
			next[temp] = next[next[temp]];
			ans += sqrt(min);
			for(j=0; k=next[j]; j=k)
			{
				if((dtemp=getdis(px[k]-px[t], py[k]-py[t])) < dis[k])
				{
					dis[k] = dtemp;
				}
			}
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}
