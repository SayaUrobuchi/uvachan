#include <stdio.h>
#include <stdlib.h>

int arr[10005], p1[10005], p2[10005];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int main()
{
	int count, n, a, b, i, j, ans;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d", &n, &a, &b);
		for(i=0; i<n; i++)
		{
			scanf("%d", &arr[i]);
		}
		qsort(arr, n, sizeof(int), comp);
		for(i=0, ans=-200000000; i<n; i++)
		{
			p1[i] = (arr[i]>=a&&arr[i]<=b) ? arr[i] : 200000000;
			p2[i] = -200000000;
			if(i && arr[i] - arr[i-1] > b)
			{
				/*printf("%d: %d\n", i, arr[i]);*/
				if(p1[i-1] != 200000000 && p1[i-1] > ans)
				{
					ans = p1[i-1];
				}
				if(p2[i-1] != -200000000 && p2[i-1] > ans)
				{
					ans = p2[i-1];
				}
			}
			else
			{
				for(j=i-1; j>=0&&arr[i]-arr[j]<=b; j--)
				{
					if(arr[i] - arr[j] >= a)
					{
						if(p2[j] != -200000000 && p2[j] + arr[i] < p1[i])
						{
							p1[i] = p2[j] + arr[i];
						}
						if(p1[j] != 200000000 && p1[j] - arr[i] > p2[i])
						{
							p2[i] = p1[j] - arr[i];
						}
					}
				}
			}
			printf("p1[%d] = %d;\n", i, p1[i]);
			printf("p2[%d] = %d;\n", i, p2[i]);
		}
		if(p1[i-1] != 200000000 && p1[i-1] > ans)
		{
			ans = p1[i-1];
		}
		if(p2[i-1] != -200000000 && p2[i-1] > ans)
		{
			ans = p2[i-1];
		}
		if(ans == -200000000)
		{
			ans = 0;
		}
		printf("%d\n", ans);
	}
	return 0;
}
