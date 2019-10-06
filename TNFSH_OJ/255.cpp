#include <stdio.h>
#include <string.h>

char name[1048576];

int main()
{
	while (fgets(name, sizeof(name), stdin))
	{
		if (strtok(name, "\r\n") == NULL)
		{
			*name = 0;
		}
		printf("Hello %s!\n", name);
	}
	return 0;
}
