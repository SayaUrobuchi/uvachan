#include <stdio.h>
#include <string.h>

int n;
int len[35];
int wayx[4] = {0, 0, 1, -1};
int wayy[4] = {1, -1, 0, 0};
char map[35][90];
char temp[35][90];
char lastline[90];

int maxvalid(int x, int y)
{
	return x > -1 && x < n && y > -1 && y < 85;
}

void floodfill(int x, int y)
{
	int i, tx, ty;
	temp[x][y] = '#';
	for(i=0; i<4; i++)
	{
		tx = x + wayx[i];
		ty = y + wayy[i];
		if(maxvalid(tx, ty))
		{
			if(temp[tx][ty] == ' ')
			{
				floodfill(tx, ty);
			}
			else if(temp[tx][ty] != '#')
			{
				map[x][y] = '#';
			}
		}
	}
}

int main()
{
	int count, i, j;
	scanf("%d", &count);
	gets(map[0]);
	while(count--)
	{
		n = 0;
		memset(map, 0, sizeof(map));
		memset(temp, ' ', sizeof(temp));
		while(gets(map[n]))
		{
			strcpy(temp[n], map[n]);
			len[n] = strlen(map[n]);
			temp[n][len[n]] = ' ';
			if(map[n][0] == '_')
			{
				for(i=0; i<n; i++)
				{
					for(j=0; map[i][j]; j++)
					{
						if(map[i][j] == '*')
						{
							map[i][j] = ' ';
							floodfill(i, j);
							break;
						}
					}
					if(map[i][j])
					{
						break;
					}
				}
				for(i=0, n++; i<n; i++)
				{
					for(j=85; j>-1; j--)
					{
						if(map[i][j] == ' ')
						{
							map[i][j] = 0;
						}
						else if(map[i][j])
						{
							break;
						}
					}
					for(; j>-1; j--)
					{
						if(!map[i][j])
						{
							map[i][j] = ' ';
						}
					}
					printf("%s\n", map[i]);
				}
				break;
			}
			else
			{
				n++;
			}
		}
	}
	return 0;
}
