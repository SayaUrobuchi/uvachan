#include <stdio.h>
#include <stdlib.h>

int px[800000], py[800000], id[800000], tmp[800000];
long long ans;

int comp(const void *p, const void *q)
{
	if(px[*(int*)p] == px[*(int*)q])
	{
		return py[*(int*)p] > py[*(int*)q] ? 1 : -1;
	}
	return px[*(int*)q] > px[*(int*)p] ? 1 : -1;
}

void ssort(int left, int right)
{
	int c, i, j, k;
	if(left >= right)
	{
		return;
	}
	c = ((left+right) >> 1);
	ssort(left, c);
	ssort(c+1, right);
	for(i=left, j=c+1; j<=right; j++, ans+=i-left)
	{
		for(; i<=c&&py[id[i]]<=py[id[j]]; i++);
	}
	for(i=left, j=c+1, k=0; i<=c&&j<=right; )
	{
		if(py[id[i]] < py[id[j]])
		{
			tmp[k++] = id[i++];
		}
		else
		{
			tmp[k++] = id[j++];
		}
	}
	for(; i<=c; )
	{
		tmp[k++] = id[i++];
	}
	for(; j<=right; )
	{
		tmp[k++] = id[j++];
	}
	for(i=left, j=0; i<=right; )
	{
		id[i++] = tmp[j++];
	}
}

int main()
{
	int count, n, i;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &px[i], &py[i]);
			id[i] = i;
		}
		qsort(id, n, sizeof(int), comp);
		ans = 0;
		ssort(0, n-1);
		printf("%lld\n", ans);
	}
	return 0;
}
