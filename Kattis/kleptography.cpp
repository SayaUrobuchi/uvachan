#include <stdio.h>

char s0[1024], s1[1024];

int main()
{
	int n, m, i;
	while (scanf("%d%d", &n, &m) == 2)
	{
		scanf("%s%s", s0+m-n, s1);
		for (i=m-n-1; i>=0; i--)
		{
			s0[i] = ((s1[i+n]-'a') + 26 - (s0[i+n]-'a'))%26 + 'a';
		}
		puts(s0);
	}
	return 0;
}
