#include <stdio.h>
#include <stdlib.h>

int parent[100005], ary[100005], last[100005], next[100005], id[100005];
long long sum[100005];

int comp(const void *p, const void *q)
{
	return ary[*(int*)q] - ary[*(int*)p];
}

int find(int now)
{
	if(parent[now])
	{
		return parent[now]=find(parent[now]);
	}
	return now;
}

int main()
{
	int n, i, j, p, q, tl, tn;
	long long ans, temp;
	while(scanf("%d", &n) == 1)
	{
		for(i=1; i<=n; i++)
		{
			scanf("%d", &ary[i]);
			last[i] = next[i] = i;
			id[i] = i;
			parent[i] = 0;
			sum[i] = ary[i];
		}
		qsort(id+1, n, sizeof(int), comp);
		for(i=1, ans=0; i<=n; i++)
		{
			p = find(id[i]);
			for(j=next[p]+1; j<=n&&ary[j]>=ary[id[i]]; j=next[p]+1)
			{
				q = find(j);
				parent[q] = p;
				next[p] = next[q];
				sum[p] += sum[q];
			}
			for(j=last[p]-1; j>0&&ary[j]>=ary[id[i]]; j=last[p]-1)
			{
				q = find(j);
				parent[q] = p;
				last[p] = last[q];
				sum[p] += sum[q];
			}
			temp = sum[p] * ary[id[i]];
			if(temp > ans)
			{
				ans = temp;
				tl = last[p];
				tn = next[p];
			}
			else if(temp == ans)
			{
				if(last[p] < tl)
				{
					tl = last[p];
					tn = next[p];
				}
				else if(last[p] == tl)
				{
					tn = next[p];
				}
			}
		}
		printf("%I64d\n%d %d\n", ans, tl, tn);
	}
	return 0;
}
