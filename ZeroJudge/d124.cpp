#include <stdio.h>

char s[1000005], *ptr;

int main()
{
	int res;
	while(gets(s))
	{
		ptr = s;
		if(*ptr == '-')
		{
			ptr++;
		}
		for(res=0; *ptr; ptr++)
		{
			res += *ptr-48;
		}
		if(res % 3)
		{
			printf("no\n");
		}
		else
		{
			printf("yes\n");
		}
	}
	return 0;
}
