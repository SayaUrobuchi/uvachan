#include <stdio.h>
#include <algorithm>

char s[1048576];

int main()
{
	int count, n, m, i, j, t;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &n, &m);
		scanf("%s", s);
		std::sort(s, s+n);
		if (m == 1)
		{
			puts(s);
			continue;
		}
		if (s[0] != s[m-1])
		{
			printf("%c\n", s[m-1]);
			continue;
		}
		for (i=m; i<n; i+=m)
		{
			if (i+m-1 >= n || s[i+m-1] != s[i])
			{
				t = i+m-1;
				if (t >= n)
				{
					t = n-1;
				}
				if (s[t] != s[t-1] && (t+1 >= n || s[t] != s[t+1]))
				{
					for (j=m; s[j]!=s[t]; j++);
					printf("%c%.*s%c\n", s[0], j-m, s+m, s[j]);
				}
				else
				{
					for (i=t%m; i<n; i+=m)
					{
						putchar(s[i]);
					}
					puts("");
					i = 0;
				}
				break;
			}
		}
		if (i >= n)
		{
			for (i=((n%m-1)+m)%m; i<n; i+=m)
			{
				putchar(s[i]);
			}
			puts("");
		}
	}
	return 0;
}
