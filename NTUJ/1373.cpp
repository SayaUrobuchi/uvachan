#include <stdio.h>
#include <stdlib.h>

int n;
int px[40005], py[40005], idx[40005];

int comp(const void *p, const void *q)
{
	return px[*(int*)p]==px[*(int*)q]?py[*(int*)p]-py[*(int*)q]:px[*(int*)p]-px[*(int*)q];
}

int get_dis(int p, int q)
{
	return (px[idx[p]]-px[idx[q]])*(px[idx[p]]-px[idx[q]])+(py[idx[p]]-py[idx[q]])*(py[idx[p]]-py[idx[q]]);
}

int recurs(int p, int q)
{
	int c, d, t, i, j;
	if(p >= q)
	{
		return 1000000000;
	}
	c = ((p+q)>>1);
	d = recurs(p, c);
	t = recurs(c+1, q);
	if(t < d)
	{
		d = t;
	}
	for(i=c-1; i>=p&&d>(px[idx[i]]-px[idx[c]])*(px[idx[i]]-px[idx[c]]); i--);
	for(i++; i<=q&&d>(px[idx[i]]-px[idx[c]])*(px[idx[i]]-px[idx[c]]); i++)
	{
		for(j=i-5; j<=i+5&&j<=q; j++)
		{
			if(i != j && j >= p)
			{
				if(get_dis(i, j) < d)
				{
					d = get_dis(i, j);
				}
			}
		}
	}
	return d;
}

int main()
{
	int i, dis, p, e;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &px[i], &py[i]);
			idx[i] = i;
		}
		qsort(idx, n, sizeof(int), comp);
		dis = recurs(0, n-1);
		scanf("%d%d", &e, &p);
		// p/((sqrt(dis)/2)^2) >= e/100
		// p*400 >= e*dis
		if(p*4000LL >= (long long)e*dis)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
	return 0;
}
