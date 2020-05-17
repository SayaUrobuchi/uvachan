#include <stdio.h>

char s[128];

int main()
{
	int n;
	while (scanf("%s%d", s, &n) == 2)
	{
		puts(((*s == 'D' && n == 25) || (*s == 'O' && n == 31)) ? "yup" : "nope");
	}
	return 0;
}
