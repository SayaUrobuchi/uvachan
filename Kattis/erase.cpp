#include <stdio.h>

char s0[1048576], s1[1048576];

int main()
{
	int n, i;
	while (scanf("%d", &n) == 1)
	{
		scanf("%s%s", s0, s1);
		for (i=0; s0[i]; i++)
		{
			if ((s0[i]^s1[i]) != (n&1))
			{
				break;
			}
		}
		if (s0[i])
		{
			puts("Deletion failed");
		}
		else
		{
			puts("Deletion succeeded");
		}
	}
	return 0;
}
