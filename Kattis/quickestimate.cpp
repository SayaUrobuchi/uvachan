#include <stdio.h>
#include <string.h>

char s[1024];

int main()
{
	int count;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%s", s);
		printf("%d\n", strlen(s));
	}
	return 0;
}
