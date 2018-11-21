#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int index[5005];
int parent[5005], num[5005];
char ary[5005][32];
char buf1[2008], buf2[2008];

int comp(const void *p, const void *q)
{
	return strcmp(ary[*(int*)p], ary[*(int*)q]);
}

int getparent(int now)
{
	if(!parent[now])
	{
		return now;
	}
	return parent[now]=getparent(parent[now]);
}

int getindex(char *s, int left, int right)
{
	int center, cmp;
	center = left + right;
	center /= 2;
	cmp = strcmp(ary[index[center]], s);
	if(!cmp)
	{
		return index[center];
	}
	else if(cmp > 0)
	{
		return getindex(s, left, center-1);
	}
	return getindex(s, center+1, right);
}

int main()
{
	int n, m, i, p, q, n1, n2, max;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(!n && !m)
		{
			break;
		}
		for(i=1; i<=n; i++)
		{
			index[i] = i;
			scanf("%s", ary[i]);
		}
		qsort(index+1, n, sizeof(int), comp);
		max = 1;
		for(i=1; i<=n; i++)
		{
			parent[i] = 0;
			num[i] = 1;
		}
		while(m--)
		{
			scanf("%s%s", buf1, buf2);
			n1 = getindex(buf1, 1, n);
			n2 = getindex(buf2, 1, n);
			if((p=getparent(n1)) != (q=getparent(n2)))
			{
				parent[p] = q;
				num[q] += num[p];
				if(num[q] > max)
				{
					max = num[q];
				}
			}
		}
		printf("%d\n", max);
	}
	return 0;
}
