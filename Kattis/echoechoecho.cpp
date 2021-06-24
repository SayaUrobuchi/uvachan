#include <iostream>

char buf[128];

int main()
{
	while (scanf("%s", buf) == 1)
	{
		printf("%s %s %s\n", buf, buf, buf);
	}
	return 0;
}
