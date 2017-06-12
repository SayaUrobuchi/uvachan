#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 1000000

int tbl[N];
int ary[5010];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int bisearch(int left, int right, unsigned int target)
{
	int center;
	if(left > right)
	{
		return -1;
	}
	center = left + right;
	center /= 2;
	if(ary[center] == target)
	{
		return center;
	}
	else if(ary[center] > target)
	{
		return bisearch(left, center-1, target);
	}
	return bisearch(center+1, right, target);
}

int maxbsearch(int left, int right, unsigned int target, int *num)
{
	int center;
	if(left > right)
	{
		return -1;
	}
	center = left + right;
	center /= 2;
	if(ary[center] > target)
	{
		return maxbsearch(left, center-1, target, num);
	}
	*num = center;
	return maxbsearch(center+1, right, target, num);
}

int minbsearch(int left, int right, unsigned int target, int *num)
{
	int center;
	if(left > right)
	{
		return -1;
	}
	center = left + right;
	center /= 2;
	if(ary[center] >= target)
	{
		*num = center;
		return minbsearch(left, center-1, target, num);
	}
	return minbsearch(center+1, right, target, num);
}

int main()
{
	int n, i, j, k, l, maximum, ans, index;
	long long sum;
	while(scanf("%d", &n) == 1)
	{
		/*memset(tbl, 0, sizeof(tbl));*/
		for(i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			/*if(ary[i] < N)
			{
				tbl[ary[i]]++;
			}*/
		}
		qsort(ary, n, sizeof(int), comp);
		maximum = ary[n-1];
		for(i=0, ans=0; i<n; i++)
		{
			for(j=i+1; j<n; j++)
			{
				sum = (unsigned int)ary[i] + ary[j];
				if(sum > maximum)
				{
					break;
				}
				/*if(sum < N)
				{
					ans += tbl[sum];
				}
				else
				{*/
					/*index = bisearch(0, n-1, sum);
					if(index != -1)
					{
						for(k=index-1; k>-1&&ary[k]==sum; k--);
						for(l=index+1; l<n&&ary[l]==sum; l++);
						ans += l - k - 1;
					}*/
					k = -1;
					maxbsearch(0, n-1, sum, &k);
					if(k != -1)
					{
						minbsearch(0, n-1, sum, &l);
						ans += k - l + 1;
					}
				/*}*/
			}
			if(j == i + 1)
			{
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
