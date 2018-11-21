#include <stdio.h>
#include <string.h>

char s[105];
char ans[105], *p;

int main()
{
	int len;
	int i;
	while (gets(s))
	{
		len = strlen(s);
		for (i=0, p=ans; i<len; i+=2)
		{
			*p++ = s[i];
		}
		*p = 0;
		printf("%s\n", ans);
	}
	return 0;
}