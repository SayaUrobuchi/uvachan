#include <stdio.h>
#include <string.h>

int tbl[128], used[128];
char str[1000000], s[1000000], cmd[1000000];

int main()
{
	int r, next, lost;
	char *p;
	while(gets(str))
	{
		sscanf(str, "%d", &r);
		if(r == -1)
		{
			break;
		}
		gets(s);
		memset(tbl, 0, sizeof(tbl));
		memset(used, 0, sizeof(used));
		for(p=s, next=0; *p; p++)
		{
			next += (tbl[*p] == 0);
			tbl[*p] = 1;
		}
		gets(cmd);
		for(p=cmd, lost=0; next&&lost<7&&*p; p++)
		{
			if(tbl[*p])
			{
				tbl[*p] = 0;
				next--;
				used[*p] = 1;
			}
			else
			{
				if(used[*p] == 0)
				{
					lost++;
					used[*p] = 1;
				}
			}
		}
		printf("Round %d\n", r);
		if(next == 0)
		{
			printf("You win.\n");
		}
		else if(lost == 7)
		{
			printf("You lose.\n");
		}
		else
		{
			printf("You chickened out.\n");
		}
	}
	return 0;
}
