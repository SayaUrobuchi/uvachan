#include <stdio.h>
#include <stdlib.h>

int n, ans, gray, list[15], ary[15];

int comp(const void *p, const void *q)
{
	return *(int*)q - *(int*)p;
}

void bisearch(int left, int right)
{
	int center, i, next;
	if(left > right)
	{
		return;
	}
	center = left + right;
	center >>= 1;
	for(i=0; i<n; i++)
	{
		list[i] = center * 50 - ary[i];
	}
	next = gray;
	while(next > 0)
	{
		qsort(list, n, sizeof(int), comp);
		if(n == 3)
		{
			list[3] = 0;
		}
		if(list[2] <= 0)
		{
			break;
		}
		if(list[2] == list[3])
		{
			list[0]--;
			list[1]--;
			next--;
			list[2]--;
		}
		else
		{
			list[0] -= list[2]-list[3];
			list[1] -= list[2]-list[3];
			next -= list[2]-list[3];
			list[2] = list[3];
		}
	}
	if(next > 0)
	{
		bisearch(center+1, right);
	}
	else
	{
		ans = center;
		bisearch(left, center-1);
	}
}

int main()
{
	int i, min, max, temp;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		for(i=0, min=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			if((temp=ary[i]/50+!(!(ary[i]%50))) > min)
			{
				min = temp;
			}
		}
		scanf("%d", &gray);
		max = min + gray/50+!(!(gray%50));
		ans = max;
		bisearch(min, max);
		printf("%d\n", ans);
	}
	return 0;
}
