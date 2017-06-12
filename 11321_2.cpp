#include <stdio.h>
#include <stdlib.h>

int m;
int ary[10001];
int tbl1[10001], tbl2[10001];
int index[10001];

int comp(const void *p, const void *q)
{
	if(tbl1[*(int*)p] < tbl1[*(int*)q])
	{
		return -1;
	}
	else if(tbl1[*(int*)p] == tbl1[*(int*)q])
	{
		if(!tbl2[*(int*)p] + !tbl2[*(int*)q] != 1)
		{
			if(tbl2[*(int*)p])
			{
				if(ary[*(int*)p] > ary[*(int*)q])
				{
					return -1;
				}
				return 1;
			}
			else
			{
				if(ary[*(int*)p] < ary[*(int*)q])
				{
					return -1;
				}
				return 1;
			}
		}
		else
		{
			if(tbl2[*(int*)p])
			{
				return -1;
			}
			else
			{
				return 1;
			}
		}
	}
	else
	{
		return 1;
	}
}

int main()
{
	int n, i;
	while(scanf("%d%d", &n, &m) == 2)
	{
		printf("%d %d\n", n, m);
		if(!n && !m)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			tbl1[i] = ary[i] % m;
			tbl2[i] = ary[i] % 2;
			index[i] = i;
		}
		qsort(index, n, sizeof(int), comp);
		for(i=0; i<n; i++)
		{
			printf("%d\n", ary[index[i]]);
		}
	}
	return 0;
}
