#include <stdio.h>
#include <string.h>

#define WHITE 0
#define BLACK 1
#define BLANK 2

int n, m;
int map[30][30];
int wayx[4] = {0, 1, 0, -1};
int wayy[4] = {1, 0, -1, 0};
char buf[1005], buf1[1005], buf2[1005];
char *ptr, *ptr1, *ptr2;

int valid(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}

int isblank(int x, int y)
{
	return !valid(x, y) || map[x][y] == BLANK;
}

int iswhite(int x, int y)
{
	return valid(x, y) && map[x][y] == WHITE;
}

void floodfill(int x, int y)
{
	int i;
	if(valid(x, y) && map[x][y] == BLACK)
	{
		map[x][y] = BLANK;
		for(i=0; i<4; i++)
		{
			floodfill(x+wayx[i], y+wayy[i]);
		}
	}
}

int main()
{
	int i, j, c;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(!n && !m)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		for(i=0; i<n; i++)
		{
			floodfill(i, 0);
			floodfill(i, m-1);
		}
		for(j=0; j<m; j++)
		{
			floodfill(0, j);
			floodfill(n-1, j);
		}
		memset(buf, ' ', sizeof(buf));
		ptr = buf;
		*ptr = 0;
		for(j=0; j<m; j++)
		{
			if(!isblank(0, j))
			{
				*ptr = ' ';
				ptr = buf + j * 5;
				memset(ptr, '+', 6);
				ptr += 6;
				*ptr = 0;
			}
		}
		/*either (a) the square below it is white and there is no white square immediately above, or 
		         (b) there is no white square immediately to its left and the square to its right is white.*/
		puts(buf);
		for(i=0, c=1; i<n; i++)
		{
			memset(buf, ' ', sizeof(buf));
			ptr = buf;
			*ptr = 0;
			memset(buf1, ' ', sizeof(buf1));
			ptr1 = buf1;
			*ptr1 = 0;
			memset(buf2, ' ', sizeof(buf2));
			ptr2 = buf2;
			*ptr2 = 0;
			for(j=0; j<m; j++)
			{
				if(map[i][j] == BLACK)
				{
					*ptr1 = ' ';
					*ptr2 = ' ';
					ptr1 = buf1 + j * 5;
					ptr2 = buf2 + j * 5;
					memset(ptr1, '+', 6);
					memset(ptr2, '+', 6);
					ptr1 += 6;
					ptr2 += 6;
					*ptr1 = 0;
					*ptr2 = 0;
				}
				else if(map[i][j] == WHITE)
				{
					if((iswhite(i+1, j) && !iswhite(i-1, j)) || (iswhite(i, j+1) && !iswhite(i, j-1)))
					{
						*ptr1 = ' ';
						*ptr2 = ' ';
						ptr1 = buf1 + j * 5;
						ptr2 = buf2 + j * 5;
						sprintf(ptr1, "+%03d +", c++);
						sprintf(ptr2, "+    +");
						ptr1 += 6;
						ptr2 += 6;
						*ptr1 = 0;
						*ptr2 = 0;
					}
					else
					{
						*ptr1 = ' ';
						*ptr2 = ' ';
						ptr1 = buf1 + j * 5;
						ptr2 = buf2 + j * 5;
						sprintf(ptr1, "+    +");
						sprintf(ptr2, "+    +");
						ptr1 += 6;
						ptr2 += 6;
						*ptr1 = 0;
						*ptr2 = 0;
					}
				}
				if(!isblank(i, j) || !isblank(i+1, j))
				{
					*ptr = ' ';
					ptr = buf + j * 5;
					memset(ptr, '+', 6);
					ptr += 6;
					*ptr = 0;
				}
			}
			puts(buf1);
			puts(buf2);
			puts(buf);
		}
		puts("");
	}
	return 0;
}
