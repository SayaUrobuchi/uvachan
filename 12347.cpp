#include <stdio.h>

int stk[1000005], rev[1000005];

int main()
{
	int n, sn, rn;
	sn = -1;
	rn = -1;
	while (scanf("%d", &n) == 1)
	{
		if (rn >= 0 && n > rev[rn])
		{
			while (sn > 0 && (rn < 0 || stk[sn] < rev[rn]))
			{
				printf("%d\n", stk[sn]);
				--sn;
			}
			--rn;
			while (rn >= 0 && n > rev[rn])
			{
				while (sn > 0 && (rn < 0 || stk[sn] < rev[rn]))
				{
					printf("%d\n", stk[sn]);
					--sn;
				}
				--rn;
			}
		}
		if (sn >= 0 && n < stk[sn])
		{
			rev[++rn] = stk[sn];
		}
		stk[++sn] = n;
	}
	while (sn >= 0)
	{
		printf("%d\n", stk[sn]);
		--sn;
	}
	return 0;
}
