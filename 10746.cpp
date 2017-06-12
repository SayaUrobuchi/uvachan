#include <stdio.h>

#define INFINITY 1000000000

int bank[30];
int from[30], bankfrom[30];
double btoc[30];
double dist[30], bankdist[30];
double map[30][30];

int main()
{
	int n, m, i, j, k, l, lim, bankptr;
	double mindist, ans;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(!n && !m)
		{
			break;
		}
		for(i=0; i<m; i++)
		{
			bank[i] = -1;
		}	
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				scanf("%lf", &map[i][j]);
			}
		}
		lim = n + m;
		for(i=0, ans=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				bankdist[j] = dist[j] = INFINITY;
			}
			for(; j<m; j++)
			{
				bankdist[j] = INFINITY;
			}
			dist[i] = 0;
			for(j=1; j<lim; j++)
			{
				for(k=0; k<n; k++)
				{
					for(l=0; l<m; l++)
					{
						if(dist[k] + map[k][l] < bankdist[l])
						{
							bankdist[l] = dist[k] + map[k][l];
							bankfrom[l] = k;
						}
					}
				}
				for(k=0; k<m; k++)
				{
					if(bank[k] != -1)
					{
						if(bankdist[k] + btoc[k] < dist[bank[k]])
						{
							dist[bank[k]] = bankdist[k] + btoc[k];
							from[bank[k]] = k;
						}
					}
				}
			}
			for(j=0, mindist=INFINITY; j<m; j++)
			{
				if(bank[j] == -1 && bankdist[j] < mindist)
				{
					mindist = bankdist[j];
					bankptr = j;
				}
			}
			ans += mindist;
			for(j=bankptr; ; )
			{
				bank[j] = bankfrom[j];
				btoc[j] = -map[bankfrom[j]][j];
				map[bankfrom[j]][j] = INFINITY + INFINITY;
				j = bankfrom[j];
				if(j == i)
				{
					break;
				}
				bank[from[j]] = -1;
				map[j][from[j]] = -btoc[from[j]];
				j = from[j];
			}
		}
		printf("%.2f\n", ans/n+1e-4);
	}
	return 0;
}
