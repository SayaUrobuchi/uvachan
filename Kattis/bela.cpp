#include <stdio.h>

char s[1024], buf[1024];
int dom[128], norm[128];

int main()
{
	int n, i, ans;
	dom['A'] = norm['A'] = 11;
	dom['K'] = norm['K'] = 4;
	dom['Q'] = norm['Q'] = 3;
	dom['J'] = norm['J'] = 2;
	dom['T'] = norm['T'] = 10;
	dom['9'] = norm['9'] = 0;
	dom['8'] = norm['8'] = 0;
	dom['7'] = norm['7'] = 0;
	dom['J'] = 20;
	dom['9'] = 14;
	while (scanf("%d%s", &n, s) == 2)
	{
		for (i=0, ans=0; i<(n<<2); i++)
		{
			scanf("%s", buf);
			ans += buf[1]==*s ? dom[*buf] : norm[*buf];
		}
		printf("%d\n", ans);
	}
	return 0;
}
