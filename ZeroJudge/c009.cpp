#include <stdio.h>

char s[1024];

int main()
{
	int n;
	while (scanf("%s", s) == 1)
	{
		if (*s == '-')
		{
			break;
		}
		if (s[1] == 'x')
		{
			sscanf(s, "%x", &n);
			printf("%d\n", n);
		}
		else
		{
			sscanf(s, "%d", &n);
			printf("0x%X\n", n);
		}
	}
	return 0;
}
