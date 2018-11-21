#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char name[20][100], n1[100], n2[100];
int ary[20], index[20];

int comp(const void *p, const void *q)
{
	return strcmp((char*)p, (char*)q);
}

int comp2(const void *p, const void *q)
{
	return ary[*(int*)p] - ary[*(int*)q];
}

int bisearch(char* target, int left, int right)
{
	int center, cmp;
	center = (left + right) / 2;
	cmp = strcmp(name[center], target);
	if(!cmp)
	{
		return center;
	}
	else if(cmp < 0)
	{
		return bisearch(target, center+1, right);
	}
	else
	{
		return bisearch(target, left, center-1);
	}
}

int main()
{
	int cas, n, t, pay, i, j, i1, i2;
	cas = 0;
	while(scanf("%d%d", &n, &t) == 2)
	{
		if(!n && !t)
		{
			break;
		}
		printf("Case #%d\n", ++cas);
		for(i=0; i<n; i++)
		{
			scanf("%s", name[i]);
		}
		qsort(name, n, sizeof(name[0]), comp);
		for(i=0; i<n; i++)
		{
			ary[i] = 0;
			index[i] = i;
		}
		while(t--)
		{
			scanf("%s%s%d", n1, n2, &pay);
			i1 = bisearch(n1, 0, n-1);
			i2 = bisearch(n2, 0, n-1);
			ary[i1] -= pay;
			ary[i2] += pay;
		}
		qsort(index, n, sizeof(int), comp2);
		for(i=0, j=n-1; i<n; )
		{
			if(!ary[index[i]])
			{
				for(; !ary[index[i]] && i<n; i++);
				if(i == n)
				{
					break;
				}
			}
			if(!ary[index[j]])
			{
				for(; !ary[index[j]] && j > -1; j--);
				if(j == -1)
				{
					break;
				}
			}
			if(ary[index[j]] > -ary[index[i]])
			{
				printf("%s %s %d\n", name[index[j]], name[index[i]], -ary[index[i]]);
				ary[index[j]] += ary[index[i]];
				ary[index[i++]] = 0;
			}
			else if(ary[index[j]] == -ary[index[i]])
			{
				printf("%s %s %d\n", name[index[j]], name[index[i]], -ary[index[i]]);
				ary[index[i++]] = 0;
				ary[index[j--]] = 0;
			}
			else
			{
				printf("%s %s %d\n", name[index[j]], name[index[i]], ary[index[j]]);
				ary[index[i]] += ary[index[j]];
				ary[index[j--]] = 0;
			}
		}
		printf("\n");
	}
	return 0;
}
