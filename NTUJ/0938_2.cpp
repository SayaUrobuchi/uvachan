#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ary[105], tbl[1400005], q[700005];

int comp(const void *p, const void *q)
{
	return *(int*)p > *(int*)q ? 1 : -1;
}

int main()
{
	int count, n, i, j, k, sum, at, ans, qn, an, temp, maxqn;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0, sum=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			sum += ary[i];
		}
		qsort(ary, n, sizeof(int), comp);
		for(i=0, ans=0, at=2147483647, an=0, maxqn=0; i<n; i++)
		{
			if(i != 0 && ary[i] == ary[i-1])
			{
				continue;
			}
			q[0] = 0;
			memset(tbl, 0, sizeof(tbl));
			tbl[0] = 1;
			for(j=0, qn=1; j<n; j++)
			{
				if(i != j)
				{
					for(k=qn-1; k>=0; k--)
					{
						if(tbl[q[k]+ary[j]] == 0)
						{
							tbl[q[k]+ary[j]] = 1;
							q[qn++] = q[k] + ary[j];
						}
					}
				}
			}
			if(qn > maxqn)
			{
				maxqn = qn;
				temp = i;
			}
		}
		i = temp;
		q[0] = 0;
		memset(tbl, 0, sizeof(tbl));
		tbl[0] = 1;
		for(j=0, qn=1; j<n; j++)
		{
			if(i != j)
			{
				for(k=qn-1; k>=0; k--)
				{
					if(tbl[q[k]+ary[j]] == 0)
					{
						tbl[q[k]+ary[j]] = 1;
						q[qn++] = q[k] + ary[j];
					}
				}
			}
		}
		for(j=1; ; j++)
		{
			if(tbl[j] == 0)
			{
				break;
			}
		}
		for(; ; j++)
		{
			if(tbl[j])
			{
				continue;
			}
			tbl[j] = 1;
			for(k=1; k<qn; k++)
			{
				if(tbl[q[k]+j])
				{
					break;
				}
			}
			if(k >= qn)
			{
				break;
			}
			tbl[j] = 0;
		}
		printf("%d %d\n", ary[i], j);
	}
	return 0;
}
