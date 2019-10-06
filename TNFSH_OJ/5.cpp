#include <stdio.h>

char str[32];

int main()
{
	scanf("%[^\n\r]", str);
	printf("Hello ,%s !\n", str);
	return 0;
}
