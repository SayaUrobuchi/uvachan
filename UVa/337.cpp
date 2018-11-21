#include <stdio.h>
#include <string.h>

int cx, cy;
char board[12][12];
char buf[10005];

void adjust()
{
	if(cx < 0)
	{
		cx = 0;
	}
	if(cx > 9)
	{
		cx = 9;
	}
	if(cy < 0)
	{
		cy = 0;
	}
	if(cy > 9)
	{
		cy = 9;
	}
}

int main()
{
	int cas, m, i, j, overwrite;
	char *ptr;
	cas = 0;
	while(gets(buf))
	{
		sscanf(buf, "%d", &m);
		if(!m)
		{
			break;
		}
		memset(board, ' ', sizeof(board));
		cx = cy = 0;
		overwrite = 1;
		while(m--)
		{
			gets(buf);
			for(ptr=buf; *ptr; ptr++)
			{
				if(*ptr == '^')
				{
					ptr++;
					if(*ptr == 'b')
					{
						cy = 0;
					}
					else if(*ptr == 'c')
					{
						memset(board, ' ', sizeof(board));
					}
					else if(*ptr == 'd')
					{
						cx++;
						adjust();
					}
					else if(*ptr == 'e')
					{
						board[cx][cy] = ' ';
					}
					else if(*ptr == 'h')
					{
						cx = cy = 0;
					}
					else if(*ptr == 'i')
					{
						overwrite = 0;
					}
					else if(*ptr == 'l')
					{
						cy--;
						adjust();
					}
					else if(*ptr == 'o')
					{
						overwrite = 1;
					}
					else if(*ptr == 'r')
					{
						cy++;
						adjust();
					}
					else if(*ptr == 'u')
					{
						cx--;
						adjust();
					}
					else if(*ptr == '^')
					{
						if(!overwrite)
						{
							for(j=9; j>cy; j--)
							{
								board[cx][j] = board[cx][j-1];
							}
						}
						board[cx][cy++] = *ptr;
						adjust();
					}
					else if(*ptr >= '0' && *ptr <= '9')
					{
						cx = *(ptr++) - '0';
						cy = *ptr - '0';
					}
				}
				else
				{
					if(!overwrite)
					{
						for(j=9; j>cy; j--)
						{
							board[cx][j] = board[cx][j-1];
						}
					}
					board[cx][cy++] = *ptr;
					adjust();
				}
			}
		}
		printf("Case %d\n", ++cas);
		printf("+----------+\n");
		for(i=0; i<10; i++)
		{
			board[i][10] = 0;
			printf("|%s|\n", board[i]);
		}
		printf("+----------+\n");
	}
	return 0;
}
