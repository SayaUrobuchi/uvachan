#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int table[400000][2], ans[400000][2], num[1001];

int comp(const void *p, const void *q)
{
	return ((int*)p)[0] * ((int*)q)[1] - ((int*)p)[1] * ((int*)q)[0];
}

int gcd(int p, int q)
{
	if(p % q)
	{
		return gcd(q, p % q);
	}
	return q;
}

int main()
{
	int n, m, i, j, k, l, tmp;
	table[0][0] = 1;
	table[0][1] = 1;
	num[1] = 1;
	for(k=2, l=1; k<1001; k++)
	{
		for(i=1; i<k; i++)
		{
			if(gcd(k, i) == 1)
			{
				table[l][0] = i;
				table[l++][1] = k;
			}
		}
		num[k] = l;
	}
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(i=0, j=num[n]; i<j; i++)
		{
			ans[i][0] = table[i][0];
			ans[i][1] = table[i][1];
		}
		qsort(ans, i, 8, comp);
		printf("%d/%d\n", ans[m-1][0], ans[m-1][1]);
	}
	return 0;
}
