#include <stdio.h>
#include <stdlib.h>

int ll[500005], rr[500005], pp[500005];

int comp(const void *p, const void *q)
{
	return ll[*(int*)p] - ll[*(int*)q];
}

int main()
{
	int count, n, m, i, j, res, last, mx;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		for(i=0; i<m; i++)
		{
			scanf("%d%d", &ll[i], &rr[i]);
			pp[i] = i;
		}
		qsort(pp, m, sizeof(int), comp);
		for(i=0, res=0, last=1; i<m; )
		{
			for(j=i, mx=-1; j<m; j++)
			{
				if(ll[pp[j]] <= last)
				{
					if(rr[pp[j]] > mx)
					{
						mx = rr[pp[j]];
					}
				}
				else
				{
					break;
				}
			}
			i = j;
			res++;
			last = mx;
			if(last == n)
			{
				break;
			}
		}
		printf("%d\n", res);
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
