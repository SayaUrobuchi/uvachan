#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAXNUM 1600000

int lnum, nnum, sq, a3, mt;
int numlist[100000], list[100000], p[150000], prime[1600001];
long long a, b, c, t, ta;

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

void dfs(long long val, int loc)
{
	if(loc == lnum)
	{
		numlist[nnum++] = val;
		return;
	}
	dfs(val, loc+1);
	val *= list[loc];
	if(val <= mt && b % val == 0)
	{
		dfs(val, loc);
	}
}

int main()
{
	int count, i, j, k, l, tt, temp;
	long long rb, rc, d;
	p[0] = 2;
	for(i=3, l=1; i<1300; i+=2)
	{
		if(prime[i] == 0)
		{
			p[l++] = i;
			for(j=i*i, k=(i<<1); j<MAXNUM; j+=k)
			{
				prime[j] = 1;
			}
		}
	}
	for(; i<MAXNUM; i+=2)
	{
		if(prime[i] == 0)
		{
			p[l++] = i;
		}
	}
	scanf("%d", &count);
	while(count--)
	{
		scanf("%lld%lld%lld", &a, &b, &c);
		mt = sq = (int)pow((double)b, 1/3.0);
		for(i=0, lnum=0; i<l&&p[i]<=mt; i++)
		{
			if(b % p[i] == 0)
			{
				list[lnum++] = p[i];
			}
		}
		nnum = 0;
		dfs(1, 0);
		qsort(numlist, nnum, sizeof(int), comp);
		for(i=0; i<nnum; i++)
		{
			t = b / numlist[i];
			ta = a - numlist[i];
			d = ta*ta - 4*t;
			rb = (int)(sqrt((double)d)+1e-10);
			if(d <= 0 || rb*rb != d)
			{
				continue;
			}
			rb = (ta - (int)(sqrt((double)d)+1e-10)) / 2;
			rc = (ta + (int)(sqrt((double)d)+1e-10)) / 2;
			if(rb * rc != t)
			{
				continue;
			}
			if((long long)numlist[i]*numlist[i] + rb*rb + rc*rc == c)
			{
				printf("%d %lld %lld\n", numlist[i], rb, rc);
				break;
			}
		}
		if(i == nnum)
		{
			printf("No solution.\n");
		}
	}
	return 0;
}
