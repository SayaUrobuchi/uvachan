#include <stdio.h>
#include <stdlib.h>

int a1[200], a2[200];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int bisearch(int p, int q, int t)
{
	int c;
	if(p > q)
	{
		return -1;
	}
	c = p + q;
	c >>= 1;
	if(a2[c]*2 == t)
	{
		return t;
	}
	else if(a2[c]*2 > t)
	{
		return bisearch(p, c-1, t);
	}
	return bisearch(c+1, q, t);
}

int main()
{
	int n, m, i, s1, s2, s, t, p, q;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0 && m == 0)
		{
			break;
		}
		for(i=0, s1=0; i<n; i++)
		{
			scanf("%d", &a1[i]);
			s1 += a1[i];
		}
		for(i=0, s2=0; i<m; i++)
		{
			scanf("%d", &a2[i]);
			s2 += a2[i];
		}
		qsort(a1, n, sizeof(int), comp);
		qsort(a2, m, sizeof(int), comp);
		for(i=0, s=2147483647; i<n; i++)
		{
			t = bisearch(0, m-1, s2+a1[i]+a1[i]-s1);
			if(t != -1)
			{
				if(t + a1[i] < s)
				{
					s = t + a1[i];
					p = a1[i];
					q = t/2;
				}
			}
		}
		if(s == 2147483647)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d %d\n", p, q);
		}
	}
	return 0;
}
