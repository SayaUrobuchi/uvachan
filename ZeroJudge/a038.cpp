#include <stdio.h>
#include <string.h>

char s[1000005];

int main()
{
	int i;
	while(gets(s))
	{
		for(i=strlen(s)-1; i>0&&s[i]=='0'; i--);
		for(; i>=0; printf("%c", s[i--]));
		printf("\n");
	}
	return 0;
}
