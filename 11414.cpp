#include <stdio.h>
#include <stdlib.h>

int n;
int ary[1005];

int comp(const void *p, const void *q)
{
	return *(int*)q - *(int*)p;
}

int main()
{
	int count, i, j, temp;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		for(i=0; i<n; i++)
		{
			qsort(ary, n, sizeof(int), comp);
			for(j=1; j<n&&ary[0]; j++)
			{
				if(ary[j] == 0)
				{
					break;
				}
				ary[j]--;
				ary[0]--;
			}
			if((j < n && ary[0]) || ary[0])
			{
				break;
			}
		}
		if(i < n)
		{
			printf("No\n");
		}
		else
		{
			printf("Yes\n");
		}
	}
	return 0;
}
