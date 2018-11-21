#include <stdio.h>

int ary[20005], h;

void heapdown(int now)
{
	int left, right, temp;
	left = (now << 1);
	right = left + 1;
	if(left < h)
	{
		if(right >= h || ary[left] < ary[right])
		{
			if(ary[left] < ary[now])
			{
				temp = ary[now];
				ary[now] = ary[left];
				ary[left] = temp;
				heapdown(left);
			}
		}
		else
		{
			if(ary[right] < ary[now])
			{
				temp = ary[now];
				ary[now] = ary[right];
				ary[right] = temp;
				heapdown(right);
			}
		}
	}
}

int main()
{
	int n, i, temp;
	long long ans;
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			scanf("%d", &ary[i+1]);
		}
		h = i + 1;
		for(i=h-1; i>=1; i--)
		{
			heapdown(i);
		}
		for(ans=0; --n; )
		{
			temp = ary[1];
			ary[1] = ary[--h];
			heapdown(1);
			ans += (ary[1] += temp);
			heapdown(1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
