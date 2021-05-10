#include <iostream>

long long c[256][256];

int main()
{
	int count, a, b;
	c[0][0] = 1;
	for (a=1; a<256; a++)
	{
		c[a][0] = 1;
		for (b=1; b<=a; b++)
		{
			c[a][b] = c[a-1][b-1] + c[a-1][b];
		}
	}
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &a, &b);
		printf("%lld\n", c[a][b-1]);
	}
	return 0;
}
