#include <stdio.h>

#define M 10020
#define MSQ 120

int tbl[M], pri[M], pn;

int main()
{
	int i, j, k, n, res, sum;
	pri[0] = 2;
	pn = 1;
	for (i=3; i<=MSQ; i+=2)
	{
		if (!tbl[i])
		{
			for (j=i*i, k=i+i; j<M; j+=k)
			{
				tbl[j] = 1;
			}
			pri[pn++] = i;
		}
	}
	for (; i<M; i+=2)
	{
		if (!tbl[i])
		{
			pri[pn++] = i;
		}
	}
	while (scanf("%d", &n) == 1)
	{
		if (!n)
		{
			break;
		}
		res = 0;
		for (i=0, j=0, sum=pri[i]; pri[i]<=n; sum-=pri[i], i++)
		{
			while (sum < n)
			{
				sum += pri[++j];
			}
			if (sum == n)
			{
				++res;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
