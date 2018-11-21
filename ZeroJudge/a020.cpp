#include <stdio.h>
#include <string.h>

char str[1000];

int main()
{
	int i;
	while(gets(str))
	{
		for(i=strlen(str)-1; i>-1; i--)
		{
			printf("%c", str[i]);
		}
		printf("\n");
	}
	return 0;
}
