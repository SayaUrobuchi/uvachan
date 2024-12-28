#include <stdio.h>
#include <algorithm>
using namespace std;

const int N = 1048576;

int heap[N], hn;
int ary[N], idx[N], cost[N];

bool comp(int p, int q)
{
	return ary[p] < ary[q];
}

bool hcomp(int p, int q)
{
	return cost[p] < cost[q];
}

int main()
{
	int n, i, t;
	long long sum, ans;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		for (i=0; i<n; i++)
		{
			scanf("%d", &cost[i]);
			idx[i] = i;
		}
		sort(idx, idx+n, comp);
		for (i=0, t=0, hn=0, sum=0, ans=0; i<n||hn; t++)
		{
			if (hn == 0)
			{
				t = ary[idx[i]];
			}
			for (; i<n&&ary[idx[i]]==t; i++)
			{
				heap[hn++] = idx[i];
				sum += cost[idx[i]];
				push_heap(heap, heap+hn, hcomp);
			}
			sum -= cost[heap[0]];
			ans += sum;
			pop_heap(heap, heap+hn, hcomp);
			hn--;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
