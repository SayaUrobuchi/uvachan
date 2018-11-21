#include <stdio.h>
#include <string.h>
#include <math.h>

int x[250], y[250], used[250], dis[250];

int getdis(int p, int q)
{
	return (x[p]-x[q])*(x[p]-x[q]) + (y[p]-y[q])*(y[p]-y[q]);
}

int max(int p, int q)
{
	return p>q ? p : q;
}

int main()
{
	int cas, n, m, i, j, t, temp;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &x[i], &y[i]);
			dis[i] = 2147483647;
		}
		memset(used, 0, sizeof(used));
		dis[0] = 0;
		for(i=0; i<n; i++)
		{
			for(j=0, m=2147483647; j<n; j++)
			{
				if(used[j] == 0 && dis[j] < m)
				{
					m = dis[j];
					temp = j;
				}
			}
			used[temp] = 1;
			if(temp == 1)
			{
				break;
			}
			for(j=0; j<n; j++)
			{
				if(used[j] == 0 && (t=max(dis[temp], getdis(temp, j))) < dis[j])
				{
					dis[j] = t;
				}
			}
		}
		printf("Scenario #%d\nFrog Distance = %.3lf\n\n", ++cas, sqrt(dis[1]));
	}
	return 0;
}
