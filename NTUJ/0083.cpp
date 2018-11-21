#include <stdio.h>

int main()
{
	int cas, count, n, q, d, i, p;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		q = n / 25;
		n %= 25;
		d = n / 10;
		n %= 10;
		i = n / 5;
		p = n % 5;
		printf("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n", ++cas, q, d, i, p);
	}
	return 0;
}
