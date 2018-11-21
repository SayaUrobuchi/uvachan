#include <stdio.h>

int map[100][100];

int main()
{
	int n, i, j, k, ans, sum;
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				scanf("%d", &map[i][j]);
				if(i)
				{
					map[i][j] += map[i-1][j];
				}
			}
		}
		for(i=0, ans=-100000000; i<n; i++)
		{
			for(j=-1; j<i; j++)
			{
				for(k=0, sum=0; k<n; k++)
				{
					sum += map[i][k];
					if(j > -1)
					{
						sum -= map[j][k];
					}
					if(sum > ans)
					{
						ans = sum;
					}
					if(sum < 0)
					{
						sum = 0;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
