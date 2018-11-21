#include <stdio.h>
#include <stdlib.h>

typedef struct data
{
	int loc, num;
}data;

data ary1[100005], ary2[100005];

int comp(const void *p, const void *q)
{
	return ((data*)p)->loc-((data*)q)->loc;
}

int main()
{
	int n, i, p, q, r, sum, temp;
	while(scanf("%d", &n) == 1)
	{
		for(i=0, sum=0; i<n; i++)
		{
			scanf("%d%d%d", &p, &q, &r);
			sum += r;
			ary1[i].loc = p;
			ary1[i].num = r;
			ary2[i].loc = q;
			ary2[i].num = r;
		}
		qsort(ary1, n, sizeof(data), comp);
		qsort(ary2, n, sizeof(data), comp);
		for(i=0, temp=0; i<n; i++)
		{
			temp += ary1[i].num;
			if(temp >= (sum+1) / 2)
			{
				break;
			}
		}
		printf("%d", ary1[i].loc);
		for(i=0, temp=0; i<n; i++)
		{
			temp += ary2[i].num;
			if(temp >= (sum+1) / 2)
			{
				break;
			}
		}
		printf(" %d\n", ary2[i].loc);
	}
	return 0;
}
