#include <stdio.h>
#include <string.h>

char str[1048576];

int main()
{
	int i, j;
	//gets(str);
	//scanf("%s", str);
	{
		/*for (i=0, j=0; str[i]; i++)
		{
			if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
			{
				str[j++] = str[i];
			}
		}
		str[j] = 0;*/
		//printf("Hello %s!\n", str);
		puts("Hello Allen!");
	}
	return 0;
}