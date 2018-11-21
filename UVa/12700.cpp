#include <stdio.h>

char s[1024];

int main()
{
	int cas, count, n, i, w, b, t;
	scanf("%d", &count);
	cas = 0;
	while (count--)
	{
		scanf("%d%s", &n, s);
		w = b = t = 0;
		for (i=0; i<n; i++)
		{
			if (s[i] == 'W')
			{
				++w;
			}
			else if (s[i] == 'B')
			{
				++b;
			}
			else if (s[i] == 'T')
			{
				++t;
			}
		}
		if (b && !w && !t)
		{
			printf("Case %d: BANGLAWASH\n", ++cas);
		}
		else if (w && !b && !t)
		{
			printf("Case %d: WHITEWASH\n", ++cas);
		}
		else if (!b && !w && !t)
		{
			printf("Case %d: ABANDONED\n", ++cas);
		}
		else if (b == w)
		{
			printf("Case %d: DRAW %d %d\n", ++cas, w, t);
		}
		else if (b > w)
		{
			printf("Case %d: BANGLADESH %d - %d\n", ++cas, b, w);
		}
		else
		{
			printf("Case %d: WWW %d - %d\n", ++cas, w, b);
		}
	}
	return 0;
}
