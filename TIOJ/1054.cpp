#include <stdio.h>
#include <string.h>

char str[7][20] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
char s[100];

int main()
{
	int n, i;
	while(scanf("%s%d", s, &n) == 2)
	{
		for(i=0; ; i++)
		{
			if(!strcmp(str[i], s))
			{
				break;
			}
		}
		i += n;
		i %= 7;
		printf("%s\n", str[i]);
	}
	return 0;
}
