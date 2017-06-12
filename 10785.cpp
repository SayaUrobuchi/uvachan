#include <stdio.h>
#include <stdlib.h>

char nam[250];
char son[]="JSBKTCLDMVNWFXGPYHQZR", mon[]="AUEOI", ss[215], mm[215];

int comp(const void *p, const void *q)
{
	return *(char*)p - *(char*)q;
}

int main()
{
	int cas, count, i, j, k, p, q, tp, tq, n;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=1, j=0, p=0, tp=0; i<=n; i+=2, j++)
		{
			if(tp == 21)
			{
				tp = 0;
				p++;
			}
			mm[j] = mon[p];
			tp++;
		}
		for(i=2, k=0, q=0, tq=0; i<=n; i+=2, k++)
		{
			if(tq == 5)
			{
				tq = 0;
				q++;
			}
			ss[k] = son[q];
			tq++;
		}
		qsort(mm, j, sizeof(char), comp);
		qsort(ss, k, sizeof(char), comp);
		for(i=1, p=0, q=0; i<=n; i++)
		{
			if(i%2)
			{
				nam[i-1] = mm[p++];
			}
			else
			{
				nam[i-1] = ss[q++];
			}
		}
		nam[i-1] = 0;
		printf("Case %d: %.*s\n", ++cas, n, nam);
	}
	return 0;
}
