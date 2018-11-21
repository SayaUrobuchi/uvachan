#include <stdio.h>

int tbl[128];
char s[1048576];

int main()
{
	int i, ans, len;
	tbl['X'] = 1;
	tbl['T'] = 2;
	tbl['S'] = 4;
	tbl['E'] = 8;
	tbl['Q'] = 16;
	tbl['H'] = 32;
	tbl['W'] = 64;
	while (gets(s))
	{
		if (*s == '*')
		{
			break;
		}
		ans = 0;
		len = 0;
		for (i=1; s[i]; i++)
		{
			if (s[i] == '/')
			{
				if (len == 64)
				{
					++ans;
				}
				len = 0;
			}
			else
			{
				len += tbl[s[i]];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
