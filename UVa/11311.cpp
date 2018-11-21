#include <stdio.h>

int main()
{
	int count, n, m, p, q;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d%d", &n, &m, &p, &q);
		if(p^q^(n-p-1)^(m-q-1))
		{
			printf("Gretel\n");
		}
		else
		{
			printf("Hansel\n");
		}
	}
	return 0;
}
