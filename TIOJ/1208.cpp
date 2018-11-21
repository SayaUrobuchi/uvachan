#include <stdio.h>
#include <string.h>

int ary[20005], sum[20005], tmp[20005], mid, now, n, m;

void sort(int left, int right)
{
	int i, j, k, center;
	if(left == right)
	{
		if(ary[left] > mid)
		{
			now++;
		}
		return;
	}
	center = ((left + right) >> 1);
	sort(left, center);
	/*if(now >= m)
	{
		return;
	}*/
	sort(center+1, right);
	/*if(now >= m)
	{
		return;
	}*/
	for(i=left, j=center+1; j<=right; j++, now+=i-left)
	{
		for(; i<=center&&ary[j]-ary[i]>mid; i++);
		/*printf("%d %d %d\n", ary[j], ary[i], mid);*/
	}
	for(i=left, j=center+1, k=0; i<=center&&j<=right; )
	{
		if(ary[i] < ary[j])
		{
			tmp[k++] = ary[i++];
		}
		else
		{
			tmp[k++] = ary[j++];
		}
	}
	if(i <= center)
	{
		for(; i<=center; )
		{
			tmp[k++] = ary[i++];
		}
	}
	if(j <= right)
	{
		for(; j<=right; )
		{
			tmp[k++] = ary[j++];
		}
	}
	/*memcpy(ary+left, tmp, sizeof(int)*k);*/
	for(i=left, j=0; i<=right; ary[i++]=tmp[j++]);
}

int main()
{
	int i, left, right, ans;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0 && m == 0)
		{
			break;
		}
		for(i=1, left=0, right=0; i<=n; i++)
		{
			scanf("%d", &sum[i]);
			if(sum[i] >= 0)
			{
				right += sum[i];
			}
			else
			{
				left += sum[i];
			}
			sum[i] += sum[i-1];
		}
		for(; left<=right; )
		{
			mid = ((left + right) >> 1);
			now = 0;
			/*memcpy(ary, sum, sizeof(sum));*/
			for(i=1; i<=n; ary[i]=sum[i], i++);
			sort(1, n);
			/*printf("NOW %d %d\n", now, mid);*/
			if(now < m)
			{
				ans = mid;
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
