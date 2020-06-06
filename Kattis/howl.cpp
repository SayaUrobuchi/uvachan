#include <stdio.h>

int tbl[128];
char s[1<<21];

int main()
{
	int n;
	tbl['O'] = 'H';
	tbl['A'] = 'H';
	tbl['H'] = 'O';
	while (scanf("%s", s) == 1)
	{
		for (n=0; s[n]; n++);
		if (s[n-1] == 'W')
		{
			if (n-2 >= 0)
			{
				s[n-1] = tbl[s[n-2]];
			}
			else
			{
				s[n-1] = 'A';
			}
		}
		s[n] = tbl[s[n-1]];
		if (s[n] == 'H')
		{
			s[++n] = 'O';
		}
		s[++n] = 'W';
		s[++n] = 0;
		puts(s);
	}
	return 0;
}
