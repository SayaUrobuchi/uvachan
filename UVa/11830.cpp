#include <stdio.h>
#include <string.h>

char s[10000005];

int main()
{
	int d, i, f;
	while(scanf("%d%s", &d, s) == 2)
	{
		if(d == 0 && strcmp(s, "0") == 0)
		{
			break;
		}
		for(i=0, f=0; s[i]; i++)
		{
			if(s[i] != d+'0')
			{
				if(f || s[i] != '0')
				{
					printf("%c", s[i]);
					f = 1;
				}
			}
		}
		if(!f)
		{
			printf("0");
		}
		printf("\n");
	}
	return 0;
}
