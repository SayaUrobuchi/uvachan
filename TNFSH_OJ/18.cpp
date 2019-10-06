#include <stdio.h>
#include <string.h>

char str[256], ss[256];

int main()
{
	int i, j;
	while (fgets(str, sizeof(str), stdin))
	{
		if (strtok(str, "\r\n") == NULL)
		{
			*str = 0;
		}
		for (i=0, j=0; str[i]; i++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				ss[j++] = str[i];
			}
			else if (str[i] >= 'a' && str[i] <= 'z')
			{
				ss[j++] = (str[i] ^ 32);
			}
		}
		for (i=0, j--; i<j&&ss[i]==ss[j]; i++, j--);
		printf(ss[i]==ss[j] ? "SETUP! %s\n" : "%s\n", str);
	}
	return 0;
}
