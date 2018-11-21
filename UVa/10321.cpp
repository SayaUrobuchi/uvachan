#include <stdio.h>
#include <stdlib.h>

int ary[10001], m;

int ab(int now)
{
	if(now < 0)
	{
		return -now;
	}
	return now;
}

int comp(const void *p, const void *q)
{
	int i, j;
	i = *(int*)p;
	j = *(int*)q;
	if(i%m == j%m)
	{
		if(ab(i)%2 == ab(j)%2)
		{
			if(ab(i) % 2)
			{
				if(j > i)
				{
					return 1;
				}
				return -1;
			}
			if(i > j)
			{
				return 1;
			}
			return -1;
		}
		else
		{
			if(ab(i) % 2)
			{
				return -1;
			}
			return 1;
		}
	}
	else
	{
		return i%m - j%m;
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
