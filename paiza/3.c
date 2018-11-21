#include <stdio.h>

int ary[300005];

int main()
{
	int n, m, i, t;
	unsigned int sum, res;
	while (scanf("%d%d", &m, &n) == 2)
	{
		res = 0;
		for (i=0, sum=0; i<n; i++)
		{
			scanf("%d", &t);
			if (i >= m)
			{
				sum -= ary[i-m];
			}
			sum += t;
			if (sum > res)
			{
				res = sum;
			}
			ary[i] = t;
		}
		printf("%u\n", res);
	}
	return 0;
}
