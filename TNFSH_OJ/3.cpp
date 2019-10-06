#include <stdio.h>

int gcd(int p, int q)
{
	while ((p%=q) && (q%=p));
	return p+q;
}

int main()
{
	int count, p, q;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &p, &q);
		printf("%d\n", gcd(p, q));
	}
	return 0;
}
