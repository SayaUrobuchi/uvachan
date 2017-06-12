#include <stdio.h>

int ary[10001], lis[10001], lis2[10001], tbl[10001], l, l2;

int bisearch(int* a, int target, int lim)
{
	int left, right, center;
	left = 0;
	right = lim;
	while(left <= right)
	{
		center = left + right;
		center /= 2;
		if(a[center] == target)
		{
			return -1;
		}
		else if(a[center] > target)
		{
			if(center)
			{
				right = center - 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			if(center == lim || a[center+1] > target)
			{
				return center + 1;
			}
			else
			{
				left = center + 1;
			}
		}
	}
}

int min(int i, int j)
{
	if(i > j)
	{
		return j;
	}
	return i;
}

int main()
{
	int n, i, temp, ans;
	while(scanf("%d", &n) == 1)
	{
		scanf("%d", &ary[0]);
		lis[0] = ary[0];
		l = 0;
		tbl[0] = 0;
		for(i=1; i<n; i++)
		{
			scanf("%d", &ary[i]);
			temp = bisearch(lis, ary[i], l);
			if(temp != -1)
			{
				lis[temp] = ary[i];
				l += (temp > l);
			}
			tbl[i] = l;
		}
		lis2[0] = ary[n-1];
		l2 = 0;
		ans = 1;
		for(i=n-2, ans=0; i>-1; i--)
		{
			temp = bisearch(lis2, ary[i], l2);
			if(temp != -1)
			{
				lis2[temp] = ary[i];
				l2 += (temp > l2);
			}
			if(l2 >= tbl[i])
			{
				ans = min(l2, tbl[i]) * 2 + 1;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
