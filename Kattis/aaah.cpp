#include <stdio.h>
#include <string.h>

char s1[1048576], s2[1048576];

int main()
{
	while (scanf("%s%s", s1, s2) == 2)
	{
		puts(strlen(s1)<strlen(s2) ? "no" : "go");
	}
	return 0;
}
