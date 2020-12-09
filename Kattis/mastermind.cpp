#include <iostream>

char s0[1024], s1[1024];

int main()
{
	int n, r, s, i, j;
	while (scanf("%d%s%s", &n, s0, s1) == 3)
	{
		for (i=0, r=0, s=0; i<n; i++)
		{
			if (s0[i] == s1[i])
			{
				++r;
				s0[i] = s1[i] = '.';
			}
		}
		for (i=0; i<n; i++)
		{
			if (s1[i] != '.')
			{
				for (j=0; j<n; j++)
				{
					if (s0[j] == s1[i])
					{
						s0[j] = s1[i] = '.';
						++s;
						break;
					}
				}
			}
		}
		printf("%d %d\n", r, s);
	}
	return 0;
}
