#include <stdio.h>

int max(int p, int q)
{
	return p>q ? p : q;
}

int min(int p, int q)
{
	return p<q ? p : q;
}

int main()
{
	int cas, count, a, b, c;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d", &a, &b, &c);
		printf("Case %d: %d\n", ++cas, a+b+c-max(a, max(b, c))-min(a, min(b, c)));
	}
	return 0;
}
