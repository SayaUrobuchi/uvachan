#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int id[400], loc[400], type[400], x1[400], x2[400], y1[400], y2[400], invl[400], invr[400];
short heap_base[10000][400];
long long sum_base[10000][400];
short *heap;
long long *sum;

int comp(const void *p, const void *q)
{
	return loc[*(int*)p] == loc[*(int*)q] ? type[*(int*)p] - type[*(int*)q] : loc[*(int*)p] - loc[*(int*)q];
}

int min(int p, int q)
{
	return p<q ? p : q;
}

int max(int p, int q)
{
	return p>q ? p : q;
}

void init(int num, int l, int r)
{
	int c;
	if(l == r)
	{
		sum[num] = invr[r] - invl[l] + 1;
		return;
	}
	c = ((l+r) >> 1);
	init(num<<1, l, c);
	init((num<<1)+1, c+1, r);
	sum[num] = sum[num<<1] + sum[(num<<1)+1];
}

void update(int num, int l, int r, int tl, int tr)
{
	int c;
	if(tl == invl[l] && tr == invr[r])
	{
		heap[num]++;
		sum[num] <<= 1;
		return;
	}
	c = ((l+r) >> 1);
	if(tl <= invr[c])
	{
		update(num<<1, l, c, tl, min(invr[c], tr));
	}
	if(tr >= invl[c+1])
	{
		update((num<<1)+1, c+1, r, max(tl, invl[c+1]), tr);
	}
	sum[num] = ((sum[num<<1]+sum[(num<<1)+1]) << heap[num]);
}

int main()
{
	int n, i, j, k, c, m, t;
	long long ans;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		for(i=0, j=0; i<n; i++)
		{
			scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
			id[j] = j;
			loc[j] = x1[i];
			type[j++] = 0;
			id[j] = j;
			loc[j] = x2[i];
			type[j++] = 1;
		}
		qsort(id, m=j, sizeof(int), comp);
		for(i=1, j=loc[id[0]], k=0, c=1, ans=loc[id[0]]*10000LL; i<m; i++)
		{
			if(c)
			{
				t = loc[id[i]] - 1;
				c -= type[id[i]] - !type[id[i]];
				if(t >= j)
				{
					invl[k] = j;
					invr[k++] = t;
				}
				j = loc[id[i]];
			}
			else
			{
				c++;
				ans += (loc[id[i]] - j) * 10000LL;
				j = loc[id[i]];
			}
		}
		ans += (10000 - j) * 10000LL;
		sum = sum_base[0];
		init(1, 0, k-1);
		for(i=1; i<10000; i++)
		{
			memcpy(sum_base[i], sum_base[i-1], sizeof(sum_base[0]));
		}
		memset(heap_base, 0, sizeof(heap_base));
		for(i=0; i<n; i++)
		{
			for(j=y1[i]; j<y2[i]; j++)
			{
				heap = heap_base[j];
				sum = sum_base[j];
				update(1, 0, k-1, x1[i], x2[i]-1);
			}
		}
		for(i=0; i<10000; i++)
		{
			ans += sum_base[i][1];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
