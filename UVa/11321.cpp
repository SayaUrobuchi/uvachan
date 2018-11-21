#include <stdio.h>
#include <stdlib.h>

int m;
int ary[10001];

int comp(const void *p, const void *q)
{
	if((*(int*)p) % m < (*(int*)q) % m)
	{
		return -1;
	}
	else if((*(int*)p) % m == (*(int*)q) % m)
	{
		if(!((*(int*)p) % 2) + !((*(int*)q) % 2) != 1)
		{
			if((*(int*)p) % 2)
			{
				if(*(int*)p > *(int*)q)
				{
					return -1;
				}
				return 1;
			}
			else
			{
				if(*(int*)p < *(int*)q)
				{
					return -1;
				}
				return 1;
			}
		}
		else
		{
			if((*(int*)p) % 2)
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
		}
		qsort(ary, n, sizeof(int), comp);
		for(i=0; i<n; i++)
		{
			printf("%d\n", ary[i]);
		}
	}
	return 0;
}
