/*
	ID: sa072682
	LANG: C
	TASK: frac1
*/
#include <stdio.h>
#include <stdlib.h>

int ary[30000][2];

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
	int n, i, j, k;
	freopen("frac1.in", "r", stdin);
	freopen("frac1.out", "w", stdout);
	scanf("%d", &n);
	printf("0/1\n");
	for(i=1, k=0; i<n; i++)
	{
		for(j=i+1; j<=n; j++)
		{
			if(gcd(i, j) == 1)
			{
				ary[k][0] = i;
				ary[k++][1] = j;
			}
		}
	}
	qsort(ary, k, sizeof(ary[0]), comp);
	for(i=0; i<k; i++)
	{
		printf("%d/%d\n", ary[i][0], ary[i][1]);
	}
	printf("1/1\n");
	scanf(" ");
	return 0;
}
