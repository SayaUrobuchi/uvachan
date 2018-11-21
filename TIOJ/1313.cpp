#include <stdio.h>

char tbl[7] = {"RLFDUB"};
char circle[12][5] = {"1574", "4751", 
					  "6238", "8326", 
					  "1432", "2341", 
					  "3478", "8743", 
					  "1265", "5621", 
					  "5687", "7865"};
char buf[5000];

void turn(char *loc, int type)
{
	int i;
	for(i=0; i<4; i++)
	{
		if(circle[type][i] == *loc)
		{
			*loc = circle[type][(i+1)%4];
			return;
		}
	}
}

int main()
{
	int i, type;
	char loc;
	char *ptr;
	while(gets(buf))
	{
		ptr = buf;
		loc = '1';
		for(; *ptr; )
		{
			for(i=0; i<6; i++)
			{
				if(*ptr == tbl[i])
				{
					type = i + i;
					break;
				}
			}
			if(*(++ptr) == '\'')
			{
				type++, ptr++;
			}
			turn(&loc, type);
		}
		printf("(%c)\n", loc);
	}
	return 0;
}
