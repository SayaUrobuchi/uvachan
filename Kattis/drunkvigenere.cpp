#include <stdio.h>

char s[1048576], t[1048576];

int main()
{
	int i, dir;
	while (scanf("%s%s", s, t) == 2)
	{
		for (i=0, dir=-1; s[i]; i++, dir=-dir)
		{
			s[i] = ((s[i]-'A') + 26 + (t[i]-'A')*dir) % 26 + 'A';
		}
		puts(s);
	}
	return 0;
}
