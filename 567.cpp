#include <stdio.h>
#include <string.h>

char path[21][21];

int main()
{
	int count, in, in2, cas;
	char i, j, k;
	cas = 0;
	while(scanf("%d", &count) == 1)
	{
		memset(path, 0, sizeof(path));
		while(count--)
		{
			scanf("%d", &in);
			path[1][in] = 1;
			path[in][1] = 1;
		}
		for(i=2; i<20; i++)
		{
			scanf("%d", &count);
			while(count--)
			{
				scanf("%d", &in);
				path[i][in] = 1;
				path[in][i] = 1;
			}
		}
		for(k=1; k<21; k++)
		{
			for(i=1; i<21; i++)
			{
				if(path[i][k])
				{
					for(j=1; j<21; j++)
					{
						if(path[k][j])
						{
							if(!path[i][j] || path[i][k] + path[k][j] < path[i][j]) path[i][j] = path[i][k] + path[k][j];
						}
					}
				}
			}
		}
		printf("Test Set #%d\n", ++cas);
		scanf("%d", &count);
		while(count--)
		{
			scanf("%d%d", &in, &in2);
			printf("%2d to %2d: %d\n", in, in2, path[in][in2]);
		}
		printf("\n");
	}
	return 0;
}
