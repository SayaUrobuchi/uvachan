#include <iostream>

char s[1048576];

int main()
{
	int n, i, a, b, m, w;
	while (scanf("%d%s", &n, s) == 2)
	{
		for (i=0, a=0, b=0, m=0, w=0; s[i]&&a+b<2; i++)
		{
			if (s[i] == 'M')
			{
				++a;
			}
			else
			{
				++b;
			}
			while (a || b)
			{
				if (a && m+1-w <= n)
				{
					--a;
					++m;
				}
				else if (b && w+1-m <= n)
				{
					--b;
					++w;
				}
				else
				{
					break;
				}
			}
		}
		printf("%d\n", m+w);
	}
	return 0;
}
