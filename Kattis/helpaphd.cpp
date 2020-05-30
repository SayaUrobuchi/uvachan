#include <stdio.h>

char buf[1048576];

int main()
{
	int count, a, b;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%s", buf);
		if (sscanf(buf, "%d + %d", &a, &b) == 2)
		{
			printf("%d\n", a+b);
		}
		else
		{
			puts("skipped");
		}
	}
	return 0;
}
