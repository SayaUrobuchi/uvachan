#include <stdio.h>
#include <string.h>

char s[2048];

int main()
{
	int count, i, len, res;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%s", s);
		for (i=0; s[i]; i++);
		len = i;
		for (i=0; i<len; i++)
		{
			s[i+len] = s[i];
		}
		res = 0;
		for (i=1; i<len; i++)
		{
			if (strncmp(s+res, s+i, len) > 0)
			{
				res = i;
			}
		}
		printf("%.*s\n", len, s+res);
	}
	return 0;
}
