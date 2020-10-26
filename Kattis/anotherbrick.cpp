#include <iostream>

int main()
{
	int n, m, o, i, j, k, t, gg;
	while (scanf("%d%d%d", &n, &m, &o) == 3)
	{
		for (i=0, j=0, k=0, gg=0; k<o; k++)
		{
			scanf("%d", &t);
			if (i < n && !gg)
			{
				if (t > m)
				{
					gg = 1;
				}
				if (j+t <= m)
				{
					j += t;
					if (j == m)
					{
						j = 0;
						++i;
					}
				}
				else
				{
					gg = 1;
				}
			}
		}
		puts((!gg && i == n) ? "YES" : "NO");
	}
	return 0;
}
