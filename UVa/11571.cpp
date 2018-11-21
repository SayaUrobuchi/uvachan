#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAXNUM 1600000

int lnum, nnum, sq;
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
	if(val < sq && b % val == 0)
	{
		dfs(val, loc);
	}
}

int bisearch(int left, int right)
{
	long long center, tmp;
	if(left > right)
	{
		return -1;
	}
	center = ((left + right) >> 1);
	tmp = center * (ta-center);
	if(tmp == t)
	{
		return (int)center;
	}
	else if(tmp > t)
	{
		return bisearch(left, center-1);
	}
	return bisearch(center+1, right);
}

int main()
{
	int count, i, j, k, l, tt, temp;
	long long rb, rc;
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
		sq = (int)pow((double)b, 1/3.0);
		for(i=0, lnum=0; i<l&&p[i]<=sq; i++)
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
			if((tt=(int)sqrt((double)t)) < ta / 2)
			{
				temp = tt;
			}
			else
			{
				temp = ta / 2;
			}
			rb = bisearch(numlist[i]+1, temp);
			rc = t / rb;
			if(rb >= rc)
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
