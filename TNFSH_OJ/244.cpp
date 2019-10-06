#include <stdio.h>

char s[1048576];

int main()
{
	int n, i;
	scanf("%d%s", &n, s);
	for (i=0; s[i]; i++)
	{
		s[i] ^= 32;
	}
	puts(s);
	return 0;
}
