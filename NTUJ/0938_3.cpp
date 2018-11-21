#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int qn;
int ary[105], tbl[1400005], q[700005];

int comp(const void *p, const void *q)
{
	return *(int*)p > *(int*)q ? 1 : -1;
}

int bisearch(int ppp, int qqq)
{
	int j, k, qq, res;
	if(ppp > qqq)
	{
		return -1;
	}
	j = ((ppp+qqq)>>1);
	qq = 0;
	if(tbl[j])
	{
		qq = 1;
	}
	else
	{
		tbl[j] = 1;
		for(k=1; k<qn; k++)
		{
			if(tbl[q[k]+j])
			{
				break;
			}
		}
		if(k < qn)
		{
			qq = 1;
		}
		tbl[j] = 0;
	}
	if(qq)
	{
		res = bisearch(ppp, j-1);
		if(res != -1)
		{
			return res;
		}
		res = bisearch(j+1, qqq);
		return res;
	}
	else
	{
		res = bisearch(ppp, j-1);
		if(res == -1)
		{
			return j;
		}
		return res;
	}
}

int main()
{
	int count, n, i, j, k, sum, at, ans, an, temp, maxqn, mx;
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
		for(j=0, qn=1, mx=0; j<n; j++)
		{
			if(i != j)
			{
				for(k=qn-1; k>=0; k--)
				{
					if(tbl[q[k]+ary[j]] == 0)
					{
						tbl[q[k]+ary[j]] = 1;
						q[qn++] = q[k] + ary[j];
						if(q[k]+ary[j] > mx)
						{
							mx = q[k] + ary[j];
						}
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
		j = bisearch(j, mx+1);
		printf("%d %d\n", ary[i], j);
	}
	return 0;
}
