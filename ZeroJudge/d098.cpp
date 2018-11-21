#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int tbl[128];
char s[1000005], *ptr;

int main()
{
	int i, res;
	for(i='0'; i<='9'; i++)
	{
		tbl[i] = 1;
	}
	while(gets(s))
	{
		res = 0;
		ptr = strtok(s, " ");
		do
		{
			for(i=0; ptr[i]; i++)
			{
				if(tbl[ptr[i]] == 0)
				{
					break;
				}
			}
			if(ptr[i] == 0)
			{
				res += atoi(ptr);
			}
		}while(ptr=strtok(NULL, " "));
		printf("%d\n", res);
	}
	return 0;
}
