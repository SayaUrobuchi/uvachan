#include <stdio.h>
#include <stdlib.h>

int px[1005], py[1005], id[1005];

int comp(const void *p, const void *q)
{
	if(px[*(int*)p] == px[*(int*)q])
	{
		return py[*(int*)p] - py[*(int*)q];
	}
	return px[*(int*)p] - px[*(int*)q];
}

int bisearch(int x, int y, int left, int right)
{
	int center;
	if(left > right)
	{
		return -1;
	}
	center = left + right;
	center >>= 1;
	if(px[id[center]] == x)
	{
		if(py[id[center]] == y)
		{
			return center;
		}
		else if(py[id[center]] > y)
		{
			return bisearch(x, y, left, center-1);
		}
		return bisearch(x, y, center+1, right);
	}
	else if(px[id[center]] > x)
	{
		return bisearch(x, y, left, center-1);
	}
	return bisearch(x, y, center+1, right);
}

int main()
{
	int n, i, j, k, c, tx, ty;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &px[i], &py[i]);
			id[i] = i;
		}
		qsort(id, n, sizeof(int), comp);
		for(i=0, c=0; i<n; i++)
		{
			for(j=i+1; j<n; j++)
			{
				if(k=bisearch(tx=px[id[i]]+py[id[j]]-py[id[i]], ty=py[id[i]]-px[id[j]]+px[id[i]], j+1, n-1) != -1)
				{
					if(bisearch(tx+px[id[j]]-px[id[i]], ty+py[id[j]]-py[id[i]], k+1, n-1) != -1)
					{
						c++;
					}
				}
				if(k=bisearch(tx=px[id[i]]-py[id[j]]+py[id[i]], ty=py[id[i]]+px[id[j]]-px[id[i]], j+1, n-1) != -1)
				{
					if(bisearch(tx+px[id[j]]-px[id[i]], ty+py[id[j]]-py[id[i]], k+1, n-1) != -1)
					{
						c++;
					}
				}
			}
		}
		printf("%d\n", c);
	}
	return 0;
}
