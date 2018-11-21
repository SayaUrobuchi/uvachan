#include <stdio.h>

int n, tbl[128], wayx[4]={0, 1, 1, 1}, wayy[4]={1, 1, 0, -1};
char map[505][505];

int valid(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < n;
}

int main()
{
	int i, j, k, l, x, y;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%s", map[i]);
		}
		for(i=0, tbl['A']=tbl['B']=tbl['C']=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				if(map[i][j] != '.')
				{
					for(k=0; k<4; k++)
					{
						if(valid(x=i-wayx[k], y=j-wayy[k]) == 0 || map[x][y] != map[i][j])
						{
							for(x=i+wayx[k], y=j+wayy[k], l=1; l<6; l++, x+=wayx[k], y+=wayy[k])
							{
								if(valid(x, y) == 0 || map[x][y] != map[i][j])
								{
									break;
								}
							}
							tbl[map[i][j]] += (l == 5);
						}
					}
				}
			}
		}
		printf("A %d\nB %d\nC %d\n\n", tbl['A'], tbl['B'], tbl['C']);
	}
	return 0;
}
