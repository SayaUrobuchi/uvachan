#include <stdio.h>
#include <string.h>

double map[305][305], u[305][305], l[305][305];

int main()
{
	int count, n, i, j, k, temp;
	double tt, res;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		memset(map, 0, sizeof(map));
		for(i=1; i<n; i++)
		{
			scanf("%d", &temp);
			map[i][temp] = map[temp][i] = 1;
		}
		for(i=0; i<n; i++)
		{
			map[i][i] = 1;
		}
		for(i=0; i<n; i++)
		{
			u[0][i] = map[0][i];
		}
		for(i=1; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				if(j < (n-1)/2)
				{
					u[i][j] = 0;
				}
				else
				{
					l[i][j] = 0;
				}
				if(i == j)
				{
					l[i][j] = 1;
				}
			}
		}
		for(i=1; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				if(j < (n-1)/2)
				{
					for(k=0, tt=map[i][j]; k<n; k++)
					{
						if(k != j)
						{
							tt -= l[i][k] * u[k][j];
						}
					}
					l[i][j] = tt / u[j][j];
				}
				else
				{
					for(k=0, tt=map[i][j]; k<n; k++)
					{
						if(k != j)
						{
							tt -= l[i][k] * u[k][j];
						}
					}
					u[i][j] = tt / l[j][j];
				}
			}
		}
		for(i=0, res=1; i<n; i++)
		{
			res *= u[i][i];
		}
		printf("%d\n", res);
	}
	return 0;
}
