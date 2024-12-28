/*
	ID: sa072682
	LANG: C
	TASK: cowtour
*/
#include <stdio.h>
#include <math.h>

int ary[150][2];
char map[150][151], chk[150][150], tbl[150];
double dis[150][151], maxdis[150], dia[150];

double getdis(int* p, int* q)
{
	return sqrt((double)(p[0]-q[0])*(double)(p[0]-q[0])+(double)(p[1]-q[1])*(double)(p[1]-q[1]));
}

int main()
{
	int n, i, j, k, c;
	double ans, temp;
	freopen("cowtour.in", "r", stdin);
	freopen("cowtour.out", "w", stdout);
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%d%d", &ary[i][0], &ary[i][1]);
	}
	for(i=0; i<n; i++)
	{
		scanf("%s", map[i]);
		for(j=0; j<n; j++)
		{
			if(map[i][j] == 49)
			{
				dis[i][j] = getdis(ary[i], ary[j]);
				chk[i][j] = 1;
			}
		}
	}
	for(k=0; k<n; k++)
	{
		for(i=0; i<n; i++)
		{
			if(i != k && chk[i][k])
			{
				for(j=0; j<n; j++)
				{
					if(k != j && i != j && chk[k][j])
					{
						if(!chk[i][j] || dis[i][k] + dis[k][j] < dis[i][j])
						{
							dis[i][j] = dis[i][k] + dis[k][j];
							chk[i][j] = 1;
						}
					}
				}
			}
		}
	}
	for(i=0, c=0; i<n; i++)
	{
		if(!tbl[i])
		{
			tbl[i] = ++c;
		}
		for(j=0; j<n; j++)
		{
			if(i != j && chk[i][j])
			{
				if(dis[i][j] > maxdis[i])
				{
					maxdis[i] = dis[i][j];
				}
				tbl[j] = tbl[i];
			}
		}
		if(maxdis[i] > dia[tbl[i]])
		{
			dia[tbl[i]] = maxdis[i];
		}
	}
	for(i=0, ans=10000000; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			if(i != j && !chk[i][j])
			{
				temp = maxdis[i] + maxdis[j] + getdis(ary[i], ary[j]);
				if(dia[0] > temp)
				{
					temp = dia[0];
				}
				if(dia[1] > temp)
				{
					temp = dia[1];
				}
				if(temp < ans)
				{
					ans = temp;
				}
			}
		}
	}
	printf("%.6f\n", ans);
	scanf(" ");
	return 0;
}
