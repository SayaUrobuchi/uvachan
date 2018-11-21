#include <stdio.h>
#include <stdlib.h>

int a[1005], b[1005], ptr[1005];

int comp(const void *p, const void *q)
{
	int pp, qq, ppp, qqq;
	pp = *(int*)p;
	qq = *(int*)q;
	ppp = 1;
	qqq = 1;
	if(a[pp]-b[pp] < 0)
	{
		ppp = 0;
	}
	if(a[qq]-b[qq] < 0)
	{
		qqq = 0;
	}
	if(ppp != qqq)
	{
		return ppp-qqq;
	}
	if(ppp)
	{
		return b[qq]-b[pp];
	}
	return a[pp]-a[qq];
}

int main()
{
	int count, n, i, at, bt;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &a[i], &b[i]);
			ptr[i] = i;
		}
		qsort(ptr, n, sizeof(int), comp);
		for(i=0, at=0, bt=0; i<n; i++)
		{
			at += a[ptr[i]];
			if(bt < at)
			{
				bt = at;
			}
			bt += b[ptr[i]];
		}
		if(at < bt)
		{
			printf("%d\n", bt);
		}
		else
		{
			printf("%d\n", at);
		}
	}
	return 0;
}
