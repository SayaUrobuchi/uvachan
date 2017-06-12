#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ary[20], sum, average;
char n, check[20];

char dfs(int now, int times, int last)
{
	int i;
	if(now == average)
	{
		if(times == 2)
		{
			return 1;
		}
		else
		{
			for(i=1; i<n; i++)
			{
				if(check[i])
				{
					check[i] = 0;
					break;
				}
			}
			if(dfs(ary[i], times+1, i))
			{
				return 1;
			}
			check[i] = 1;
		}
		return 0;
	}
	for(i=last+1; i<n; i++)
	{
		if(check[i])
		{
			if(now + ary[i] > average)
			{
				continue;
			}
			check[i] = 0;
			if(dfs(now + ary[i], times, i))
			{
				return 1;
			}
			check[i] = 1;
			if(now + ary[i] == average)
			{
				return 0;
			}
		}
	}
	return 0;
}

int comp(const void *p, const void *q)
{
	return *(int*)q - *(int*)p;
}

int main()
{
	int count, i, j, tmp;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		sum = 0;
		for(i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			sum += ary[i];
		}
		if(sum % 4)
		{
			printf("no\n");
			continue;
		}
		average = sum >> 2;
		for(i=0; i<n; i++)
		{
			if(ary[i] > average)
			{
				printf("no\n");
				break;
			}
		}
		if(i < n)
		{
			continue;
		}
		qsort(ary, n, 4, comp);
		memset(check, 1, n);
		check[0] = 0;
		if(dfs(ary[0], 0, 0))
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}
	return 0;
}