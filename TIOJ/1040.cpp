#include <stdio.h>

void gcd(int p, int q, int chk)
{
	if(p % q)
	{
		if(chk)
		{
			printf("{");
		}
		printf("%d+1/", p/q);
		gcd(q, p%q, chk+1);
		if(chk)
		{
			printf("}");
		}
	}
	else
	{
		printf("%d", p/q);
	}
}

int main()
{
	int count, n, m;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		printf("%d/%d = ", n, m);
		gcd(n, m, 0);
		printf("\n");
	}
	return 0;
}
