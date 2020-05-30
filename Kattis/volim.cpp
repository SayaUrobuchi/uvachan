#include <stdio.h>

char s[8];

int main()
{
	int m, i, t, u, cur, ans;
	while (scanf("%d%d", &cur, &m) == 2)
	{
		for (--cur, t=0, i=0; i<m; i++)
		{
			scanf("%d%s", &u, s);
			if (t < 3*60+30 && t+u >= 3*60+30)
			{
				ans = cur;
			}
			t += u;
			if (*s == 'T')
			{
				cur = ((cur+1) & 7);
			}
		}
		printf("%d\n", ans+1);
	}
	return 0;
}
