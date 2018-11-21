#include <stdio.h>

int p[16384], q[16384];
char nam[16384][32];

int main()
{
	int count, n, m, i, t, res;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=0; i<n; i++)
		{
			scanf("%s%d%d", nam[i], &p[i], &q[i]);
		}
		scanf("%d", &m);
		while (m--)
		{
			scanf("%d", &t);
			res = -1;
			for (i=0; i<n; i++)
			{
				if (p[i] <= t && q[i] >= t)
				{
					if (res >= 0)
					{
						res = -2;
						break;
					}
					else
					{
						res = i;
					}
				}
			}
			if (res < 0)
			{
				puts("UNDETERMINED");
			}
			else
			{
				puts(nam[res]);
			}
		}
		if (count)
		{
			puts("");
		}
	}
	return 0;
}
