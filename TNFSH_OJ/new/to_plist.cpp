#include <stdio.h>

char s[100005];

int main()
{
	int a;
	while (gets(s))
	{
		if (sscanf(s, "%d", &a) == 1)
		{
			printf("UVa%d,", a);
		}
	}
	puts("");
	return 0;
}
