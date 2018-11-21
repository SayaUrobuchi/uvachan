#include <stdio.h>
#include <stdlib.h>

int aryx[10000], aryy[10000];
int index[10000];

int comp(const void *p, const void *q)
{
	return aryx[*(int*)p]*aryy[*(int*)q] - aryx[*(int*)q]*aryy[*(int*)p];
}

int gcd(int p, int q)
{
	if(p % q)
	{
		return gcd(q, p%q);
	}
	return q;
}

int main()
{
	int n, i, j, k;
	while(scanf("%d", &n) == 1)
	{
		for(i=1, k=0; i<n; i++)
		{
			for(j=i+1; j<=n; j++)
			{
				if(gcd(i, j) == 1)
				{
					index[k] = k;
					aryx[k] = i;
					aryy[k++] = j;
				}
			}
		}
		qsort(index, k, sizeof(int), comp);
		printf("%d\n", k);
		n--;
		if(n >= k)
		{
			n = k-1;
		}
		printf("%d/%d\n", aryx[index[n]], aryy[index[n]]);
	}
	return 0;
}
