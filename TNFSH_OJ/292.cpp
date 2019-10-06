#include <stdio.h>

char s[1048576];

void recurs(int cur, int p)
{
	if (cur >= p)
	{
		recurs(cur/p, p);
	}
	printf("%d", cur%p);
}

int main()
{
	int a, b, i, val;
	while (scanf("%d%d%s", &a, &b, s) == 3)
	{
		for (val=0, i=0; s[i]; val=val*a+(s[i]-'0'), i++);
		recurs(val, b);
		puts("");
	}
	return 0;
}
