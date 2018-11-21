#include <stdio.h>

char s[1048576];

int main()
{
	int cas;
	cas = 0;
	while (gets(s))
	{
		if (*s == '*')
		{
			break;
		}
		++cas;
		if (*s == 'H')
		{
			printf("Case %d: Hajj-e-Akbar\n", cas);
		}
		else
		{
			printf("Case %d: Hajj-e-Asghar\n", cas);
		}
	}
	return 0;
}
