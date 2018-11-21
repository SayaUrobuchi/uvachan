#include <stdio.h>
#include <string.h>

char map[32][33];

int main()
{
	int count, cas, x, y, i;
	char command[1025], tmp;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		memset(map, '.', sizeof(map));
		for(i=0; i<32; i++) map[i][32] = 0;
		scanf("%d%d", &y, &x);
		x = 31 - x;
		scanf("%s", command);
		for(i=0; command[i]!='.'; i++)
		{
			tmp = command[i];
			if(tmp == 'N')
			{
				map[x][y] = 'X';
				x--;
			}
			else if(tmp == 'S')
			{
				map[x+1][y-1] = 'X';
				x++;
			}
			else if(tmp == 'E')
			{
				map[x+1][y] = 'X';
				y++;
			}
			else
			{
				map[x][y-1] = 'X';
				y--;
			}
		}
		printf("Bitmap #%d\n", ++cas);
		for(i=0; i<32; i++) puts(map[i]);
		puts("");
	}
	return 0;
}
