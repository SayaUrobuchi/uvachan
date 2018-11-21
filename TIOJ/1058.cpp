#include <stdio.h>
#include <string.h>

char s1[10000], s2[10000];
char stemp1[10000], stemp2[10000];
char buf1[10000], buf2[10000];
char next1[10000], next2[10000];

int main()
{
	while(scanf("%s%s", s1, s2) == 2)
	{
		strcpy(stemp1, s1);
		strcpy(stemp2, s2);
		sprintf(buf1, "%20s", strtok(s1, "."));
		if(strcmp(s1, stemp1))
		{
			strcpy(next1, strtok(NULL, "."));
		}
		sprintf(buf2, "%20s", strtok(s2, "."));
		if(strcmp(s2, stemp2))
		{
			strcpy(next2, strtok(NULL, "."));
		}
		if(!strcmp(buf1, buf2))
		{
			if(strcmp(next1, next2) > 0)
			{
				printf("%s\n", stemp1);
			}
			else
			{
				printf("%s\n", stemp2);
			}
		}
		else if(strcmp(buf1, buf2) > 0)
		{
			printf("%s\n", stemp1);
		}
		else
		{
			printf("%s\n", stemp2);
		}
	}
	return 0;
}
