#include <iostream>

char s[1048576];

int main()
{
	int i, a, b, c;
	while (scanf("%s", s) == 1)
	{
		for (i=1, a=0, b=0, c=0; s[i]; i++)
		{
			if (s[i] != 'U')
			{
				a += 2;
			}
			if (s[i] != 'D')
			{
				b += 2;
			}
			if (s[i] != s[i-1])
			{
				++c;
			}
		}
		if (*s == 'D')
		{
			if (s[1] == 'D')
			{
				--a;
			}
			else
			{
				++a;
			}
		}
		if (*s == 'U')
		{
			if (s[1] == 'U')
			{
				--b;
			}
			else
			{
				++b;
			}
		}
		printf("%d\n%d\n%d\n", a, b, c);
	}
	return 0;
}
