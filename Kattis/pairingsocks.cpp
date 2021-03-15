#include <iostream>

int stk[1048576], sn;

int main()
{
	int n, i, t;
	while (scanf("%d", &n) == 1)
	{
		n <<= 1;
		for (i=0, sn=0; i<n; i++)
		{
			scanf("%d", &t);
			if (!sn || stk[sn-1] != t)
			{
				stk[sn++] = t;
			}
			else
			{
				--sn;
			}
		}
		printf(sn?"impossible\n":"%d\n", n);
	}
	return 0;
}