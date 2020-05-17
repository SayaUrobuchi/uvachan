#include <stdio.h>

char s[128];

int main()
{
	int n, m, i, c, t, ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0, ans=0, c=0; i<m; i++)
		{
			scanf("%s%d", s, &t);
			if (*s == 'e')
			{
				if (c+t > n)
				{
					ans++;
				}
				else
				{
					c += t;
				}
			}
			else
			{
				c -= t;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
