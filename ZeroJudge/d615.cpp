#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int has[128], s[1000005];
char buf[1000005];
long long ns[1000005];

int main()
{
	int count, sn, nsn;
	char *ptr, p;
	long long res;
	has['+'] = has['-'] = 1;
	has['*'] = has['/'] = 2;
	gets(buf);
	sscanf(buf, "%d", &count);
	while(count--)
	{
		gets(buf);
		p = '+';
		res = 0;
		ptr = strtok(buf, " ");
		do
		{
			if(has[*ptr] == 0)
			{
				if(p == '+')
				{
					res += atoi(ptr);
				}
				else if(p == '-')
				{
					res -= atoi(ptr);
				}
				else if(p == '*')
				{
					res *= atoi(ptr);
				}
				else if(p == '/')
				{
					res /= atoi(ptr);
				}
			}
			else
			{
				p = *ptr;
			}
		}while(ptr=strtok(NULL, " "));
		printf("%lld\n", res);
	}
	return 0;
}
