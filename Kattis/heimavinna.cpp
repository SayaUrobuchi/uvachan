#include <iostream>

char s[1048576], buf[1048576];

int main()
{
	int d, r, ans, a, b;
	char *p;
	while (scanf("%s", s) == 1)
	{
		p = s;
		ans = 0;
		while (sscanf(p, "%[^;]%n", buf, &d) == 1)
		{
			r = sscanf(buf, "%d-%d", &a, &b);
			if (r == 1)
			{
				b = a;
			}
			ans += b-a+1;
			p += d;
			if (*p++ == 0)
			{
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
