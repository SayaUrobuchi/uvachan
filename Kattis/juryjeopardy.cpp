#include <iostream>

const int MOD = 256;
const int EAST = 1;

int ucnt;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int record[1024][1024];
char s[1048576];

int main()
{
	int count, i, j, x, y, d, top, bottom, right;
	scanf("%d", &count);
	printf("%d\n", count);
	while (count--)
	{
		scanf("%s", s);
		++ucnt;
		top = bottom = right = 0;
		x = y = 0;
		record[x+MOD][y] = ucnt;
		d = EAST;
		for (i=0; s[i]; i++)
		{
			if (s[i] == 'R')
			{
				d = ((d+1)&3);
			}
			else if (s[i] == 'L')
			{
				d = ((d+3)&3);
			}
			else if (s[i] == 'B')
			{
				d = ((d+2)&3);
			}
			x += dx[d];
			y += dy[d];
			record[x+MOD][y] = ucnt;
			if (x < top)
			{
				top = x;
			}
			if (x > bottom)
			{
				bottom = x;
			}
			if (y > right)
			{
				right = y;
			}
		}
		printf("%d %d\n", bottom+1-(top-1)+1, right+1+1);
		for (i=top-1; i<=bottom+1; i++)
		{
			for (j=0; j<=right+1; j++)
			{
				putchar(record[i+MOD][j]==ucnt?'.':'#');
			}
			putchar('\n');
		}
	}
	return 0;
}
