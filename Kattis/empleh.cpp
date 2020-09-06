#include <stdio.h>
#include <string.h>

const char *bdr = "+---+---+---+---+---+---+---+---+";
const char *cc = ".:";

char board[16][16];
char buf[1048576];

int main()
{
	int x, y, i, j;
	char *ptr, c;
	while (scanf(" %[^\n]", buf) == 1)
	{
		memset(board, 0, sizeof(board));
		for (ptr=strchr(buf, ':')+1; *ptr; )
		{
			if (*ptr == ',' || *ptr == ' ')
			{
				++ptr;
			}
			if (*ptr)
			{
				if (*(ptr+1) >= '0' && *(ptr+1) <= '9')
				{
					c = 'P';
				}
				else
				{
					c = *ptr;
					++ptr;
				}
				y = *ptr++ - 'a';
				x = 8 - (*ptr++ - '0');
				board[x][y] = c;
			}
		}
		scanf(" %[^\n]", buf);
		for (ptr=strchr(buf, ':')+1; *ptr; )
		{
			if (*ptr == ',' || *ptr == ' ')
			{
				++ptr;
			}
			if (*(ptr+1) >= '0' && *(ptr+1) <= '9')
			{
				c = 'p';
			}
			else
			{
				c = *ptr^32;
				++ptr;
			}
			y = *ptr++ - 'a';
			x = 8 - (*ptr++ - '0');
			board[x][y] = c;
		}
		puts(bdr);
		for (i=0; i<8; i++)
		{
			putchar('|');
			for (j=0; j<8; j++)
			{
				printf((i+j)&1?":%c:|":".%c.|", board[i][j]?board[i][j]:cc[(i+j)&1]);
			}
			puts("");
			puts(bdr);
		}
	}
	return 0;
}
