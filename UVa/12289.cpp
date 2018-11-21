#include <stdio.h>

char s[6];

int main()
{
	int count;
	gets(s);
	sscanf(s, "%d", &count);
	while(count--)
	{
		gets(s);
		if(s[3])
		{
			puts("3");
		}
		else if((s[0]=='t')+(s[1]=='w')+(s[2]=='o') >= 2)
		{
			puts("2");
		}
		else
		{
			puts("1");
		}
	}
	return 0;
}
