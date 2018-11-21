#include <stdio.h>
#include <stdlib.h>

int ary[1000], sum[1000000][2];

int comp(const void *p, const void *q)
{
	return *(int*)q - *(int*)p;
}

int binarysearch(int min, int max, int target)
{
	int center;
	if(min > max)
	{
		return -1;
	}
	center = min + max;
	center /= 2;
	if(sum[center][0] == target)
	{
		if(center && sum[center-1][0] == target)
		{
			return binarysearch(min, center-1, target);
		}
		return center;
	}
	else if(sum[center][0] < target)
	{
		return binarysearch(min, center-1, target);
	}
	else
	{
		return binarysearch(center+1, max, target);
	}
}

int main()
{
	int n, i, j, snum, tmp, ptr;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		for(i=0, snum=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			for(j=0; j<i; j++)
			{
				sum[snum][0] = ary[i] + ary[j];
				sum[snum++][1] = ary[i];
			}
		}
		qsort(ary, n, 4, comp);
		qsort(sum, snum, 8, comp);
		for(i=0; i<n; i++)
		{
			for(j=i+1; j<n; j++)
			{
				tmp = ary[i] - ary[j];
				ptr = binarysearch(0, snum-1, tmp);
				for(; sum[ptr][0]==tmp; ptr++)
				{
					if(ary[j] != sum[ptr][1] && ary[j] != sum[ptr][0] - sum[ptr][1])
					{
						if(ary[i] != sum[ptr][1] && ary[i] != sum[ptr][0] - sum[ptr][1])
						{
							tmp = -1;
							break;
						}
					}
				}
				if(tmp == -1)
				{
					break;
				}
			}
			if(j < n)
			{
				break;
			}
		}
		if(i == n)
		{
			printf("no solution\n");
		}
		else
		{
			printf("%d\n", ary[i]);
		}
	}
	return 0;
}