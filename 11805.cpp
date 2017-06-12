#include <stdio.h>

int main()
{
	int count, a, b, c, cas;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d", &a, &b, &c);
		b += c-1;
		printf("Case %d: %d\n", ++cas, b%a+1);
	}
	return 0;
}
