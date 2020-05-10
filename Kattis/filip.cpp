#include <stdio.h>

int main()
{
	int a, b, i, p, q;
	while (scanf("%d%d", &a, &b) == 2)
	{
		for (i=0, p=0, q=0; i<3; a/=10, b/=10, i++)
		{
			p = p*10 + a%10;
			q = q*10 + b%10;
		}
		printf("%d\n", p>q ? p : q);
	}
	return 0;
}
