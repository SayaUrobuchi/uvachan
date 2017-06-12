#include <stdio.h>
#include <string.h>

int value, flag;
char buf[2008];

void calc(int n)
{
	value <<= n;
	if(flag)
	{
		value += (1<<n) - 1;
	}
}

int main()
{
	int l;
	value = 0;
	while(scanf("%s", buf) == 1)
	{
		if(buf[0] == '~')
		{
			break;
		}
		if(buf[0] == '#')
		{
			printf("%d\n", value);
			value = 0;
		}
		else
		{
			l = strlen(buf);
			if(l == 1)
			{
				flag = 1;
			}
			else if(l == 2)
			{
				flag = 0;
			}
			else
			{
				calc(l-2);
			}
		}
	}
	return 0;
}
