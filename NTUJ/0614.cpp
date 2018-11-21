#include <stdio.h>
#include <string.h>

char str[1000005];

int main()
{
	int i, len, res;
	while(gets(str))
	{
		if(strcmp(str, "#") == 0)
		{
			break;
		}
		for(i=1, len=1, res=1; str[i]; i++)
		{
			if(str[i] == str[i-1]+1)
			{
				len++;
				if(len > res)
				{
					res = len;
				}
			}
			else
			{
				len = 1;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
