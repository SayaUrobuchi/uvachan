#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int table[400000][2];

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
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(k=1, l=0, n++; k<n; k++)
		{
			for(i=1; i<k; i++)
			{
				if(gcd(k, i) == 1)
				{
					table[l][0] = i;
					table[l++][1] = k;
				}
			}
		}
		qsort(table, l, 8, comp);
		table[l][0] = 1;
		table[l][1] = 1;
		printf("%d/%d\n", table[m-1][0], table[m-1][1]);
	}
	return 0;
}
