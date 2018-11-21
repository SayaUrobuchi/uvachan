#include <stdio.h>

int main()
{
	int n, m, l1, l2, c1, c2, r1, r2;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 1 && m == 1)
		{
			break;
		}
		l1 = 0;
		l2 = 1;
		c1 = 1;
		c2 = 1;
		r1 = 1;
		r2 = 0;
		while(1)
		{
			if(n * c2 > m * c1)
			{
				l1 = c1;
				l2 = c2;
				c1 = l1 + r1;
				c2 = l2 + r2;
				printf("R");
			}
			else
			{
				r1 = c1;
				r2 = c2;
				c1 = l1 + r1;
				c2 = l2 + r2;
				printf("L");
			}
			if(c1 == n && c2 == m)
			{
				break;
			}
		}
		printf("\n");
	}
	return 0;
}
