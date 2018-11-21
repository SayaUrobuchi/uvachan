#include <stdio.h>
#include <string.h>

char s[256];

int main()
{
	long long n, i;
	char *p;
	while (fgets(s, 10004, stdin))
	{
		s[strlen(s)-1] = 0;
		if (*s >= '0' && *s <= '9')
		{
			n = 0;
			for (p=s; *p; p++)
			{
				n = n*10 + (*p-'0');
			}
			for (i=0; i<52; i++)
			{
				if (n & (1LL << i))
				{
					printf("%c", (i<26?'A'+i:'a'+(i-26)));
				}
			}
			puts("");
		}
		else
		{
			n = 0;
			for (p=s; *p; p++)
			{
				if (*p >= 'A' && *p <= 'Z')
				{
					n += (1LL << (*p-'A'));
				}
				else
				{
					n += (1LL << ((*p-'a')+26));
				}
			}
			printf("%lld\n", n);
		}
	}
	return 0;
}
