#include <stdio.h>

char s[65536], t[65536];

int main()
{
	int n, i;
	while (scanf("%s%s", s, t) == 2)
	{
		for (n=0; t[n]; n++);
		for (i=0; s[i]; i++)
		{
			t[i+n] = (s[i]-'A'-(t[i]-'A')+26)%26 + 'A';
			s[i] = t[i+n];
		}
		puts(s);
	}
	return 0;
}
