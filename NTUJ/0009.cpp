#include <stdio.h>
#include <stdlib.h>

int px[100], py[100], id[100], ary[200];

int comp(const void *p, const void *q)
{
	if(px[*(int*)p] == px[*(int*)q])
	{
		return py[*(int*)p] - py[*(int*)q];
	}
	return px[*(int*)p] - px[*(int*)q];
}

int cross(int p, int q, int r)
{
	return (px[r]-px[q])*(py[q]-py[p]) - (py[r]-py[q])*(px[q]-px[p]);
}

int main()
{
	int n, m, i, t;
	n = 0;
	while(scanf("%d%d", &px[n], &py[n]) == 2)
	{
		id[n] = n;
		n++;
	}
	qsort(id, n, sizeof(int), comp);
	for(i=0, m=0; i<n; i++)
	{
		for(; m>=2&&cross(ary[m-2], ary[m-1], id[i])>=0; m--);
		ary[m++] = id[i];
	}
	for(i=n-2, t=m+1; i>=0; i--)
	{
		for(; m>=t&&cross(ary[m-2], ary[m-1], id[i])>=0; m--);
		ary[m++] = id[i];
	}
	for(i=0; i<m&&ary[i]; i++);
	for(t=i; i<m; i++)
	{
		printf("(%d,%d)\n", px[ary[i]], py[ary[i]]);
	}
	for(i=1; i<t; i++)
	{
		printf("(%d,%d)\n", px[ary[i]], py[ary[i]]);
	}
	scanf(" ");
	return 0;
}
