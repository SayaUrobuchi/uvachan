#include <stdio.h>

int map[1005][1005];

int main()
{
	int n, i, j, f;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		for(i=0, f=1; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				scanf("%d", &map[i][j]);
				if(i && j)
				{
					f &= (map[i][j]+map[i-1][j-1] == map[i][j-1]+map[i-1][j]);
				}
			}
		}
		if(f)
		{
			printf("homogeneous\n");
		}
		else
		{
			printf("not homogeneous\n");
		}
	}
	return 0;
}
