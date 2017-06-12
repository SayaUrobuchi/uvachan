#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int index[1000];
int start[1000], elesize[1000], dimension[1000];
int lbound[1000][15], rbound[1000][15];
int product[1000][15];
char name[1000][15];
char str[15];

int comp(const void *p, const void *q)
{
	return strcmp(name[*(int*)p], name[*(int*)q]);
}

int bisearch(int left, int right)
{
	int center, cmp;
	center = left + right;
	center /= 2;
	cmp = strcmp(name[index[center]], str);
	if(!cmp)
	{
		return index[center];
	}
	else if(cmp > 0)
	{
		return bisearch(left, center-1);
	}
	return bisearch(center+1, right);
}

int main()
{
	int n, m, i, j, d, sum, target;
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(i=0; i<n; i++)
		{
			scanf("%s%d%d%d", name[i], &start[i], &elesize[i], &dimension[i]);
			for(j=0; j<dimension[i]; j++)
			{
				scanf("%d%d", &lbound[i][j], &rbound[i][j]);
			}
			product[i][j-1] = 1;
			for(j=dimension[i]-2; j>-1; j--)
			{
				product[i][j] = product[i][j+1] * (rbound[i][j+1]-lbound[i][j+1]+1);
			}
			index[i] = i;
		}
		qsort(index, n, sizeof(int), comp);
		while(m--)
		{
			scanf("%s%d", str, &d);
			target = bisearch(0, n-1);
			printf("%s[%d", name[target], d);
			for(i=1, sum=(d-lbound[target][0])*product[target][0]; i<dimension[target]; i++)
			{
				scanf("%d", &d);
				printf(", %d", d);
				sum += (d-lbound[target][i]) * product[target][i];
			}
			sum *= elesize[target];
			sum += start[target];
			printf("] = %d\n", sum);
		}
	}
	return 0;
}
