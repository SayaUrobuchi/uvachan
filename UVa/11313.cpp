#include <stdio.h>

int main()
{
	int count, n, m;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		n -= m;
		if(n % (m-1))
		{
			printf("cannot do this\n");
		}
		else
		{
			printf("%d\n", n/(m-1)+1);
		}
	}
	return 0;
}
