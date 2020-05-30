#include <stdio.h>

char s[1024];

int main()
{
	int n, i, gg, last, t;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, last=0, gg=0; i<n; i++)
		{
			scanf("%s", s);
			if (sscanf(s, "%d", &t) == 1)
			{
				if (t != last+1)
				{
					gg = 1;
				}
			}
			++last;
		}
		puts(gg?"something is fishy":"makes sense");
	}
	return 0;
}
