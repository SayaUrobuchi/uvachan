#include <stdio.h>

int main()
{
	int count, n, m;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		if(n == m)
		{
			n = (n+1) / 2;
			printf("%d\n", (n+1) * n / 2);
		}
		else
		{
			printf("%d\n", ((n+1) / 2) * ((m+1) / 2));
		}
	}
	return 0;
}
