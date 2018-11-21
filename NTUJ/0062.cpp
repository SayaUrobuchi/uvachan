#include <stdio.h>
#include <stdlib.h>

int ary[100005];

int comp(const void *p, const void *q)
{
	return *(int*)q - *(int*)p;
}

int main()
{
	int n, i, k, p, q, c, ans, temp;
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		scanf("%d", &k);
		qsort(ary, n, sizeof(int), comp);
		if(k == 1)
		{
			printf("%d\n", ary[0]);
			continue;
		}
		p = 1;
		q = ary[0];
		for(; p<=q; )
		{
			c = ((p+q) >> 1);
			for(i=0, temp=0; i<n; i++)
			{
				if(ary[i] > c)
				{
					temp += (ary[i]-c-1) / (k-1) + 1;
					if(temp > c)
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
			if(temp > c)
			{
				p = c+1;
			}
			else
			{
				ans = c;
				q = c-1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
