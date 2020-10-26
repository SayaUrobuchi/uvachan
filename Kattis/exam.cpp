#include <iostream>

char s0[1048576], s1[1048576];

int main()
{
	int n, m, i, t;
	while (scanf("%d", &m) == 1)
	{
		scanf("%s%s", s0, s1);
		for (i=0, t=0; s0[i]; i++)
		{
			if (s0[i] == s1[i])
			{
				++t;
			}
		}
		n = i;
		if (t >= m)
		{
			printf("%d\n", m+(n-t));
		}
		else
		{
			printf("%d\n", n-(m-t));
		}
	}
	return 0;
}
