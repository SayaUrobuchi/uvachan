#include <iostream>

int stk[1048576];

int main()
{
	int n, m, i, sum, sn, t;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0, sn=0; i<m; i++)
		{
			if (scanf("%d", &t) != 1)
			{
				scanf("%*s%d", &t);
				sn -= t;
			}
			else
			{
				stk[sn++] = t;
			}
		}
		for (i=0, sum=0; i<sn; i++)
		{
			sum += stk[i];
		}
		printf("%d\n", (sum%n+n)%n);
	}
	return 0;
}
