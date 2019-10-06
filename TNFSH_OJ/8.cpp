#include <stdio.h>
#include <string.h>

char str[1024];

int main()
{
	int n, i, j, len;
	while (scanf("%d", &n) == 1)
	{
		fgets(str, sizeof(str), stdin);
		fgets(str, sizeof(str), stdin);
		if (!strtok(str, "\r\n"))
		{
			*str = 0;
		}
		for (len=0; str[len]; len++);
		for (i=0; i<n; i++)
		{
			for (j=i; j<len; j+=n)
			{
				putchar(str[j]);
			}
		}
		puts("");
	}
	return 0;
}
