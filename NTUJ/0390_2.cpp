#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int arr[10005], adp[10005], bdp[10005], aused[10005], bused[10005], n, a, b;

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int recura(int);

int recurb(int now)
{
	int i;
	if(bused[now])
	{
		return bdp[now];
	}
	bused[now] = 1;
	bdp[now] = -2147483647;
	for(i=now+1; i<n&&arr[i]-arr[now]<=b; i++)
	{
		if(arr[i] - arr[now] >= a)
		{
			if(recura(i) - arr[now] > bdp[now])
			{
				bdp[now] = recura(i) - arr[now];
			}
		}
	}
	if(bdp[now] == -2147483647)
	{
		bdp[now] = -arr[now];
	}
	return bdp[now];
}

int recura(int now)
{
	int i;
	if(aused[now])
	{
		return adp[now];
	}
	aused[now] = 1;
	adp[now] = 2147483647;
	for(i=now+1; i<n&&arr[i]-arr[now]<=b; i++)
	{
		if(arr[i] - arr[now] >= a)
		{
			if(recurb(i) + arr[now] < adp[now])
			{
				adp[now] = recurb(i) + arr[now];
			}
		}
	}
	if(adp[now] == 2147483647)
	{
		adp[now] = arr[now];
	}
	return adp[now];
}

int main()
{
	int count, i, j, ans;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d", &n, &a, &b);
		for(i=0; i<n; i++)
		{
			scanf("%d", &arr[i]);
		}
		qsort(arr, n, sizeof(int), comp);
		memset(aused, 0, sizeof(aused));
		memset(bused, 0, sizeof(bused));
		for(i=0, ans=-2147483647; i<n&&arr[i]<=b; i++)
		{
			if(arr[i] >= a)
			{
				if(recura(i) > ans)
				{
					ans = recura(i);
				}
			}
		}
		if(ans == -2147483647)
		{
			ans = 0;
		}
		printf("%d\n", ans);
	}
	return 0;
}
