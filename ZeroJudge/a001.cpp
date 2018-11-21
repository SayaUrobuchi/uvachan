#include <stdio.h>

char str[10000];

int main()
{
	while(gets(str))
	{
		printf("Hello %s\n", str);
	}
	return 0;
}
