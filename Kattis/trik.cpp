#include <stdio.h>
#include <algorithm>

char s[1048576];

int main()
{
	int a, b, c, i;
	while (scanf("%s", s) == 1)
	{
		a = 1;
		b = c = 0;
		for (i=0; s[i]; i++)
		{
			if (s[i] == 'A')
			{
				std::swap(a, b);
			}
			else if (s[i] == 'B')
			{
				std::swap(b, c);
			}
			else
			{
				std::swap(a, c);
			}
		}
		printf("%d\n", a?1:(b?2:3));
	}
	return 0;
}
