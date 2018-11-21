#include <stdio.h>
#include <string.h>

int path[40][40];

int main()
{
	int count, n, i, j, k, cas;
	cas = 0;
	while(scanf("%d", &count) == 1)
	{
		n = 0;
		memset(path, 0, sizeof(path));
		while(count--)
		{
			scanf("%d%d", &i, &j);
			if(i > n) n = i;
			if(j > n) n = j;
			path[i][j] = 1;
		}
		n++;
		for(k=0; k<n; k++)
		{
			for(i=0; i<n; i++)
			{
				if(path[i][k])
				{
					for(j=0; j<n; j++)
					{
						if(path[k][j] && path[i][j] != -1)
						{
							if(i == j) path[i][j] = -1;
							else
							{
								if(path[i][i] == -1 || path[k][k] == -1 || path[j][j] == -1 || path[i][k] == -1 || path[k][j] == -1)
								{
									path[i][j] = -1;
								}
								else
								{
									path[i][j] += path[i][k] * path[k][j];
								}
							}
						}
					}
				}
			}
		}
		printf("matrix for city %d\n", cas++);
		for(i=0; i<n; i++)
		{
			printf("%d", path[i][0]);
			for(j=1; j<n; j++)
			{
				printf(" %d", path[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
