#include <iostream>
#include <cstring>

char s0[1024], s1[1024], cmd[1024];

int main()
{
	int n, n0, n1, m, i;
	while (scanf("%s%s%s", s0, cmd, s1) == 3)
	{
		n0 = strlen(s0);
		n1 = strlen(s1);
		if (*cmd == '*')
		{
			putchar('1');
			for (i=0; i<n0+n1-2; i++)
			{
				putchar('0');
			}
			puts("");
		}
		else
		{
			putchar(n0==n1?'2':'1');
			n = (n0>n1?n0:n1);
			m = (n0>n1?n0-n1:n1-n0);
			for (i=1; i<n; i++)
			{
				putchar(i==m?'1':'0');
			}
			puts("");
		}
	}
	return 0;
}
