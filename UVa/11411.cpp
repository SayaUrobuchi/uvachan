#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define N 5000001

int tbl[N];
int ary[N];
int hash[400];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int main()
{
	int count, n, i, j, k, a, b, sq, left, right, max, times;
	for(i=1; i<N; i++)
	{
		tbl[i] = 1;
	}
	for(i=4; i<N; i+=2)
	{
		tbl[i] = 2;
	}
	sq = (int)sqrt((double)N) + 1;
	for(i=3; i<sq; i+=2)
	{
		if(tbl[i] == 1)
		{
			for(j=i*i, k=i+i; j<N; j+=k)
			{
				tbl[j] = i;
			}
		}
	}
	for(i=2; i<N; i++)
	{
		if(tbl[i] == 1)
		{
			tbl[i] = 2;
		}
		else
		{
			for(j=i, k=1; !(j%tbl[i]); j/=tbl[i], k++);
			/*if(i == 6) printf("%d %d %d\n", j, tbl[j], k);*/
			tbl[i] = tbl[j] * k;
		}
		/*if(tbl[i] >= 400)
		{
			printf("XDDD %d\n", tbl[i]);
		}*/
	}
	/*for(i=1; i<100; i++)
	{
		printf("%d: %d\n", i, tbl[i]);
	}*/
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &a, &b);
		memset(hash, 0, sizeof(hash));
		for(i=0, j=a; j<=b; j++)
		{
			if(hash[tbl[j]] < 2)
			{
				ary[i++] = tbl[j];
				hash[tbl[j]]++;
			}
		}
		qsort(ary, i, sizeof(int), comp);
		n = i;
		for(i=1, left=right=ary[0], max=0; i<n; i++)
		{
			if(left < right)
			{
				if(ary[i]-left > max)
				{
					max = ary[i] - left;
				}
				left = ary[i];
			}
			else
			{
				if(ary[i] - right > max)
				{
					max = ary[i] - right;
				}
				right = ary[i];
			}
		}
		if(left > right)
		{
			if(right - left > max)
			{
				max = right - left;
			}
		}
		else
		{
			if(left - right > max)
			{
				max = left - right;
			}
		}
		printf("%d\n", max);
	}
	return 0;
}
