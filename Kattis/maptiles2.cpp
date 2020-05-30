#include <stdio.h>
#include <string.h>

char s[1048576];

int main()
{
	int n, i, x, y, t;
	while (scanf("%s", s) == 1)
	{
		n = strlen(s);
		for (i=0, x=0, y=0; i<n; i++)
		{
			t = s[i]-'0';
			if (t & 1)
			{
				x += (1<<(n-i-1));
			}
			if (t & 2)
			{
				y += (1<<(n-i-1));
			}
		}
		printf("%d %d %d\n", n, x, y);
	}
	return 0;
}
