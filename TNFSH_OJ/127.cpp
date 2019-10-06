#include <stdio.h>

char ss[1048576];

int main()
{
	int n, i;
	while (scanf("%d%s", &n, ss) == 2)
	{
		for (i=0; ss[i]; i++)
		{
			ss[i] -= n;
			if (ss[i] < 'A')
			{
				ss[i] += 26;
			}
		}
		puts(ss);
	}
	return 0;
}
