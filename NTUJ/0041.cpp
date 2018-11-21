#include <stdio.h>
#include <string.h>

char s[1000000], board[1000000], cmd[1000000], buf[1000000];

int main()
{
	int n, i, j, temp;
	char *q, *l, *r;
	while(scanf("%d", &n) == 1)
	{
		q = s;
		*q = 0;
		i = j = 0;
		board[0] = 0;
		while(n--)
		{
			scanf("%s", cmd);
			if(strcmp(cmd, "ADD") == 0)
			{
				scanf("%s", buf);
				*(q++) = buf[0];
				*q = 0;
			}
			else if(strcmp(cmd, "SELECT") == 0)
			{
				scanf("%d%d", &i, &j);
			}
			else if(strcmp(cmd, "CANCEL") == 0)
			{
				i = j = 0;
			}
			else if(strcmp(cmd, "COPY") == 0)
			{
				if(i)
				{
					sprintf(board, "%.*s\0", j-i+1, s+i-1);
				}
			}
			else if(strcmp(cmd, "PASTE") == 0)
			{
				if(board[0])
				{
					strcpy(q, board);
					q += strlen(q);
				}
			}
			else if(strcmp(cmd, "REVERSE") == 0)
			{
				for(l=s, r=q-1; l<r; l++, r--)
				{
					temp = *l;
					*l = *r;
					*r = temp;
				}
			}
		}
		printf("%s\n", s);
	}
	return 0;
}
