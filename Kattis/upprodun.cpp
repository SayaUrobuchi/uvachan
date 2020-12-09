#include <iostream>

char s[1024];

int main()
{
	int n, m, a, b, i;
	for (i=0; i<512; i++)
	{
		s[i] = '*';
	}
	s[i] = 0;
	while (scanf("%d%d", &n, &m) == 2)
	{
		a = m/n;
		b = m%n;
		for (i=0; i<n; i++)
		{
			printf("%.*s\n", a+(i<b?1:0), s);
		}
	}
	return 0;
}
