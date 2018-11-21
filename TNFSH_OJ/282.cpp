#include <stdio.h>
#include <algorithm>
using namespace std;

struct H1
{
	int id, stat;
};

int h1n, h2n;
int ary[200005][3], stat[200005];
int heap2[200005];
H1 heap1[200005];

bool comp1(H1 p, H1 q)
{
	if (ary[p.id][p.stat] != ary[q.id][q.stat])
	{
		return ary[p.id][p.stat] > ary[q.id][q.stat];
	}
	return p.stat < q.stat;
}

bool comp2(int p, int q)
{
	return ary[p][2] > ary[q][2];
}

int get_next_h1()
{
	while (h1n > 0 && stat[heap1[0].id] != heap1[0].stat)
	{
		pop_heap(heap1, heap1+h1n, comp1);
		h1n--;
	}
	if (h1n == 0)
	{
		return -1;
	}
	return heap1[0].id;
}

int get_next_h2()
{
	while (h2n > 0 && stat[heap2[0]])
	{
		pop_heap(heap2, heap2+h2n, comp2);
		h2n--;
	}
	if (h2n == 0)
	{
		return -1;
	}
	return heap2[0];
}

int main()
{
	int n, m, i, p1, p2, q1, cur, ans, h1sum, h2sum;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d%d", &ary[i][1], &ary[i][0]);
			ary[i][2] = ary[i][1];
			ary[i][1] -= ary[i][0];
			heap1[i].id = i;
			heap1[i].stat = 0;
			heap2[i] = i;
			stat[i] = 0;
		}
		h1n = n;
		h2n = n;
		make_heap(heap1, heap1+h1n, comp1);
		make_heap(heap2, heap2+h2n, comp2);
		cur = 0;
		ans = 0;
		while (cur <= m && (h1n || h2n))
		{
			p1 = get_next_h1();
			pop_heap(heap1, heap1+h1n, comp1);
			h1n--;
			q1 = get_next_h1();
			p2 = get_next_h2();
			h1sum = 0;
			if (p1 != -1)
			{
				h1sum = ary[p1][stat[p1]];
				if (q1 != -1)
				{
					h1sum += ary[q1][stat[q1]];
				}
			}
			h2sum = 0;
			if (p2 != -1)
			{
				h2sum = ary[p2][2];
			}
			if (h2sum == 0 || h1sum < h2sum || cur + h2sum > m)
			{
				cur += ary[p1][stat[p1]];
				//printf("select 1: %d %d, cur: %d\n", p1, ary[p1][stat[p1]], cur);
				if (cur <= m)
				{
					ans++;
					stat[p1]++;
					if (stat[p1] < 2)
					{
						heap1[h1n].id = p1;
						heap1[h1n].stat = stat[p1];
						h1n++;
						push_heap(heap1, heap1+h1n, comp1);
					}
				}
			}
			else
			{
				cur += h2sum;
				//printf("select 2: %d %d, cur: %d\n", p2, ary[p2][2], cur);
				if (cur <= m)
				{
					ans += 2;
					pop_heap(heap2, heap2+h2n, comp2);
					h2n--;
				}
				heap1[h1n].id = p1;
				heap1[h1n].stat = stat[p1];
				h1n++;
				push_heap(heap1, heap1+h1n, comp1);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
