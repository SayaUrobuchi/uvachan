#include <iostream>

char s[1048576];

int main()
{
	int n, i, j, k, best;
	while (scanf("%s", s) == 1)
	{
		for (n=0; s[n]; n++);
		for (i=2, best=1; i*i<=n; i++)
		{
			if (n%i == 0)
			{
				best = i;
			}
		}
		for (j=0; j<best; j++)
		{
			for (k=j; k<n; k+=best)
			{
				putchar(s[k]);
			}
		}
		puts("");
	}
	return 0;
}
