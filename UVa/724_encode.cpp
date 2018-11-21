#include <stdio.h>

int main()
{
	char c;
	freopen("1.txt", "w", stdout);
	while(scanf("%c", &c) == 1)
	{
		if(c == '\t')
		{
			printf("\\t");
		}
		else if(c == '\n')
		{
			printf("\\n");
		}
		else if(c == '"')
		{
			printf("\\\"");
		}
		else if(c == '\\')
		{
			printf("\\\\");
		}
		else
		{
			putchar(c);
		}
	}
	return 0;
}
