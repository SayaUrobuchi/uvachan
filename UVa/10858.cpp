#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int ary[3000], list[25], ans[100000][25], num[100000], n, count, lim;

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

void dfs(int last, int depth, long long value)
{
	int i;
	if(value > n)
	{
		return;
	}
	if(value == n)
	{
		for(i=0; i<depth; i++)
		{
			ans[count][i] = list[i];
		}
		num[count] = depth;
		count++;
		return;
	}
	for(i=last; i<lim; i++)
	{
		list[depth] = ary[i];
		dfs(i, depth+1, value*ary[i]);
	}
}

int main()
{
	int i, j, s, sq;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		if(n == 1)
		{
			printf("0\n");
			continue;
		}
		for(i=2+n%2, j=0, s=1+n%2, sq=sqrt(n)+1; i<sq; i+=s)
		{
			if(!(n % i))
			{
				ary[j++] = i;
				if(i * i != n)
				{
					ary[j++] = n / i;
				}
			}
		}
		count = 0;
		lim = j;
		qsort(ary, lim, sizeof(int), comp);
		dfs(0, 0, 1);
		printf("%d\n", count);
		for(i=0; i<count; i++)
		{
			printf("%d", ans[i][0]);
			for(j=1; j<num[i]; j++)
			{
				printf(" %d", ans[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
