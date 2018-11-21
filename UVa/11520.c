#include <stdio.h>

int n, wx[4] = {0, 1, 0, -1}, wy[4] = {1, 0, -1, 0};
char map[20][20];

int getmap(int x, int y)
{
	if(x >= 0 && x < n && y >= 0 && y < n)
	{
		return map[x][y];
	}
	return 0;
}

int main()
{
	int cas, count, i, j, k, l;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%s", map[i]);
		}
		printf("Case %d:\n", ++cas);
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				if(map[i][j] == '.')
				{
					for(k='A'; k<='Z'; k++)
					{
						for(l=0; l<4; l++)
						{
							if(k == getmap(i+wx[l], j+wy[l]))
							{
								break;
							}
						}
						if(l == 4)
						{
							break;
						}
					}
					map[i][j] = k;
				}
			}
			printf("%s\n", map[i]);
		}
	}
	return 0;
}
