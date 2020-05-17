#include <stdio.h>

const int N = 256;
char s[N], t[N];

int main()
{
	int count, i;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%s%s", s, t);
		puts(s);
		puts(t);
		for (i=0; s[i]; i++)
		{
			putchar(s[i]==t[i]?'.':'*');
		}
		puts("");
		puts("");
	}
	return 0;
}