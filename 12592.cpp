#include <stdio.h>
#include <string.h>

char s[1024], p[32][1024], q[32][1024];

int main()
{
	int n, m, i;
	scanf("%d", &n);
	gets(p[0]);
	for (i=0; i<n; i++)
	{
		gets(p[i]);
		gets(q[i]);
	}
	scanf("%d", &m);
	gets(s);
	while (m--)
	{
		gets(s);
		for (i=0; i<n; i++)
		{
			if (strcmp(s, p[i]) == 0)
			{
				puts(q[i]);
				break;
			}
		}
	}
	return 0;
}
