#include <iostream>

char s[1024];

int main()
{
	int n, i, ans;
	char c;
	while (scanf("%d", &n) == 1)
	{
		scanf("%s", s);
		c = *s;
		for (i=1, ans=0; i<n; i++)
		{
			scanf("%s", s);
			if (c == *s)
			{
				++ans;
			}
			c = *s;
		}
		printf("%d\n", ans);
	}
	return 0;
}
