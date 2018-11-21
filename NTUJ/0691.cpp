#include <stdio.h>
#include <string.h>

int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[] = {1, -1, 0, 0, 1, 1, -1, -1};
int mine[50][50];
char map[50][50];

int main()
{
	int count, n, m, i, j, k, f, gg, tx, ty;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		memset(mine, 0, sizeof(mine));
		for(i=0; i<n; i++)
		{
			scanf("%s", map[i]);
		}
		for(i=0, gg=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				if(map[i][j] == 'F')
				{
					for(k=0, f=0; k<8; k++)
					{
						tx = i + dx[k];
						ty = j + dy[k];
						if(tx >= 0 && tx < n && ty >= 0 && ty < m && map[tx][ty] != 'F')
						{
							f = 1;
							mine[tx][ty]++;
						}
					}
					if(f == 0)
					{
						gg = 1;
					}
				}
			}
		}
		if(!gg)
		{
			for(i=0; i<n; i++)
			{
				for(j=0; j<m; j++)
				{
					if(map[i][j] != 'F' && map[i][j] - 48 != mine[i][j])
					{
						break;
					}
				}
				if(j < m)
				{
					break;
				}
			}
		}
		if(i < n || gg)
		{
			printf("Please sweep the mine again!\n");
		}
		else
		{
			printf("Well done Clark!\n");
		}
	}
	return 0;
}
