#include <stdio.h>
#include <math.h>

int x[101], y[101];
int conn[101][101];
double map[101][101];

double dis(int x1, int y1, int x2, int y2)
{
	x1 -= x2;
	y1 -= y2;
	x1 *= x1;
	y1 *= y1;
	return sqrt(x1+y1);
}

int main()
{
	int cas, count, n, i, j, k, flag;
	double maximum;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &x[i], &y[i]);
			for(j=0; j<i; j++)
			{
				map[i][j] = map[j][i] = dis(x[i], y[i], x[j], y[j]);
				conn[i][j] = conn[j][i] = (map[i][j] <= 10);
			}
			map[i][i] = conn[i][i] = 0;
		}
		for(k=0; k<n; k++)
		{
			for(i=0; i<n; i++)
			{
				if(conn[i][k] && i != k)
				{
					for(j=0; j<n; j++)
					{
						if(conn[k][j] && k != j && i != j)
						{
							if(!conn[i][j] || map[i][k] + map[k][j] < map[i][j])
							{
								conn[i][j] = 1;
								map[i][j] = map[i][k] + map[k][j];
							}
						}
					}
				}
			}
		}
		for(i=0, maximum=-1, flag=0; i<n; i++)
		{
			for(j=0; j<i; j++)
			{
				if(conn[i][j] && map[i][j] > maximum)
				{
					maximum = map[i][j];
				}
				else if(!conn[i][j])
				{
					flag = 1;
				}
			}
		}
		if(maximum < 0 || flag)
		{
			printf("Case #%d:\nSend Kurdy\n\n", ++cas);
		}
		else
		{
			printf("Case #%d:\n%.4lf\n\n", ++cas, maximum);
		}
	}
	return 0;
}
