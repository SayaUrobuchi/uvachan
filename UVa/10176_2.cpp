#include <stdio.h>

int main()
{
	int res;
	char c;
	res = 0;
	while(scanf("%c", &c) == 1)
	{
		if(c == '\n')
		{
			continue;
		}
		else if(c == '#')
		{
			if(res)
			{
				printf("NO\n");
			}
			else
			{
				printf("YES\n");
			}
			res = 0;
		}
		else
		{
			res <<= 1;
			res += c - 48;
			res %= 131071;
		}
	}
	return 0;
}
