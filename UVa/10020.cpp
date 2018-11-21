#include <stdio.h>
#include <stdlib.h>

int list[10000];
int l[100001], r[100001];
int index[100001];

int comp(const void *p, const void *q)
{
	return l[*(int*)p] - l[*(int*)q];
}

int main()
{
	int count, n, m, i, j, now, maxlength;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &m);
		for(i=0; ; i++)
		{
			scanf("%d%d", &l[i], &r[i]);
			if(!l[i] && !r[i])
			{
				break;
			}
			index[i] = i;
		}
		n = i;
		qsort(index, n, sizeof(int), comp);
		for(i=0, j=0, now=0; i<n; j++)
		{
			for(maxlength=-1; i<n; i++)
			{
				if(l[index[i]] <= now && r[index[i]] >= now)
				{
					if(r[index[i]] > maxlength)
					{
						maxlength = r[index[i]];
						list[j] = index[i];
					}
				}
				else if(l[index[i]] > now)
				{
					break;
				}
			}
			if(maxlength >= now)
			{
				now = maxlength;
				if(now >= m)
				{
					break;
				}
			}
			else if(maxlength == -1)
			{
				break;
			}
		}
		if(now >= m)
		{
			printf("%d\n", ++j);
			for(i=0; i<j; i++)
			{
				printf("%d %d\n", l[list[i]], r[list[i]]);
			}
		}
		else
		{
			printf("0\n");
		}
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
