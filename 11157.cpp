#include <stdio.h>

char s[128];

int main()
{
	int count, cas, n, m, p, q, ans, d, i;
	cas = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &n, &m);
		p = q = 0;
		ans = 0;
		for (i=0; i<n; i++)
		{
			scanf("%s", s);
			sscanf(s+2, "%d", &d);
			if (d-p > ans)
			{
				ans = d-p;
			}
			if (*s == 'B')
			{
				p = q = d;
			}
			else
			{
				p = q;
				q = d;
			}
		}
		if (m-p > ans)
		{
			ans = m-p;
		}
		printf("Case %d: %d\n", ++cas, ans);
	}
	return 0;
}
