#include <stdio.h>
#include <string.h>

int llnot[4], logic[2];
char ch[4];

int main()
{
	int count, type;
	char str[10000], *s;
	scanf("%d", &count);
	gets(str);
	while(count--)
	{
		gets(str);
		s = strtok(str, " ");
		type = 0;
		memset(llnot, 0, sizeof(llnot));
		memset(logic, 0, sizeof(logic));
		do
		{
			if(s[1])
			{
				if(!strcmp(s, "not"))
				{
					llnot[type] = 1;
				}
				else if(!strcmp(s, "THEN"))
				{
					type = 2;
				}
				else if(!strcmp(s, "and"))
				{
					logic[type/2] = 1;
				}
				else if(!strcmp(s, "or"))
				{
					logic[type/2] = 2;
				}
			}
			else
			{
				ch[type++] = s[0];
			}
		}while(s = strtok(NULL, " "));
		printf("IF");
		if(!llnot[2])
		{
			printf(" not");
		}
		printf(" %c", ch[2]);
		if(logic[1])
		{
			if(logic[1] == 1)
			{
				printf(" or");
			}
			else
			{
				printf(" and");
			}
			if(!llnot[3])
			{
				printf(" not");
			}
			printf(" %c", ch[3]);
		}
		printf(" THEN");
		if(!llnot[0])
		{
			printf(" not");
		}
		printf(" %c", ch[0]);
		if(logic[0])
		{
			if(logic[0] == 1)
			{
				printf(" or");
			}
			else
			{
				printf(" and");
			}
			if(!llnot[1])
			{
				printf(" not");
			}
			printf(" %c", ch[1]);
		}
		printf("\n");
	}
	return 0;
}
