#include <stdio.h>
#include <string.h>

char p[1048576], q[1048576];

int main()
{
	int a, b, c, d, e, f;
	char *r, *s;
	while(scanf("%s%s", &p, &q) == 2)
	{
		sscanf(p, "%d", &a);
		sscanf(q, "%d", &b);
		if (a < 0 || b < 0 || *p == '-' || *q == '-')
		{
			puts("Fake");
			continue;
		}
		if (a != b)
		{
			puts("Fake");
			continue;
		}
		r = strchr(p, '.');
		s = strchr(q, '.');
		if (r && s)
		{
			while(*r && *s)
			{
				if (*r != *s)
				{
					break;
				}
				r++;
				s++;
			}
			if (*r && *s)
			{
				puts("Fake");
				continue;
			}
			if (!*r && !*s)
			{
				puts("Nymphia");
				continue;
			}
			c = 0;
			if (*r)
			{
				while (*r)
				{
					if (*r != '0')
					{
						c = 1;
						break;
					}
					r++;
				}
			}
			else
			{
				while (*s)
				{
					if (*s != '0')
					{
						c = 1;
						break;
					}
					s++;
				}
			}
			puts(c ? "Fake" : "Nymphia");
		}
		else if (!r && !s)
		{
			puts(a == b ? "Nymphia" : "Fake");
		}
		else
		{
			c = 0;
			if (r)
			{
				while (*++r)
				{
					if (*r != '0')
					{
						c = 1;
						break;
					}
					r++;
				}
			}
			else
			{
				while (*++s)
				{
					if (*s != '0')
					{
						c = 1;
						break;
					}
					s++;
				}
			}
			puts(c ? "Fake" : "Nymphia");
		}
	}
	return 0;
}
