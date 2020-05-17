#include <stdio.h>

char s[1048576];

int main()
{
	int i, a, b, c, d;
	while (scanf("%s", s) == 1)
	{
		for (i=0, a=b=c=d=0; s[i]; i++)
		{
			if (s[i] == '_')
			{
				++a;
			}
			else if (s[i] >= 'a' && s[i] <= 'z')
			{
				++b;
			}
			else if (s[i] >= 'A' && s[i] <= 'Z')
			{
				++c;
			}
			else
			{
				++d;
			}
		}
		printf("%.10lf\n%.10lf\n%.10lf\n%.10lf\n", a*1./i, b*1./i, c*1./i, d*1./i);
	}
	return 0;
}
