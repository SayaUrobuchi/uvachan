#include <stdio.h>

char buf[1048576];

int main()
{
	int i, j;
	buf[0] = buf[1] = '0';
	while (scanf("%s", buf+2) == 1)
	{
		for (i=2; buf[i]; i++);
		for (j=i%3; buf[j]; j+=3)
		{
			putchar('0'+(((buf[j]-'0')<<2)+((buf[j+1]-'0')<<1)+buf[j+2]-'0'));
		}
		puts("");
	}
	return 0;
}
