#include <stdio.h>

char s[1048576];

int main()
{
	int a, b, i;
	while (scanf("%s", s) == 1)
	{
		for (a=0, b=-1, i=0; s[i]; b=-b, i++)
		{
			a += (s[i]-'0')*b;
		}
		printf("%d\n", a<0?-a:a);
	}
	return 0;
}
