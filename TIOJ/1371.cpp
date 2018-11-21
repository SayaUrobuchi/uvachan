#include <stdio.h>
#include <stdlib.h>

int px[100005], py[100005], id[100005], ary[200010];

int comp(const void *p, const void *q)
{
	if(px[*(int*)p] == px[*(int*)q])
	{
		return py[*(int*)p] - py[*(int*)q];
	}
	return px[*(int*)p] - px[*(int*)q];
}

int numcomp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

long long cross(int p, int q, int r)
{
	long long x1, x2, y1, y2;
	x1 = px[q] - px[p];
	x2 = px[r] - px[q];
	y1 = py[q] - py[p];
	y2 = py[r] - py[q];
	return x1*y2-x2*y1;
}

int main()
{
	int n, i, m, t;
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &px[i], &py[i]);
			id[i] = i;
		}
		qsort(id, n, sizeof(int), comp);
		for(i=0, m=0; i<n; i++)
		{
			for(; m>=2&&cross(ary[m-2], ary[m-1], id[i])<=0; m--);
			ary[m++] = id[i];
		}
		for(i=n-2, t=m+1; i>=0; i--)
		{
			for(; m>=t&&cross(ary[m-2], ary[m-1], id[i])<=0; m--);
			ary[m++] = id[i];
		}
		qsort(ary, m, sizeof(int), numcomp);
		for(i=0, t=0; i<m; i++)
		{
			if(i == 0 || ary[i] != ary[i-1])
			{
				t++;
			}
		}
		printf("%d\n", t);
		for(i=0, t=0; i<m; i++)
		{
			if(i == 0 || ary[i] != ary[i-1])
			{
				t++;
				printf("%d\n", ary[i]+1);
			}
		}
	}
	return 0;
}
