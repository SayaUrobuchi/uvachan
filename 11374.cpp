#include <stdio.h>
#include <string.h>
#include <algorithm>

const int N2 = 1024;
const int M2 = 2048;

int n, ex, exm;
int adj[N2][M2], adjd[N2][M2], an[N2];
int dis[N2], used[N2], from[N2];

struct hnode
{
	int id, dis;
};

int hn;
hnode heap[M2<<1];

bool comp(struct hnode p, struct hnode q)
{
	return p.dis > q.dis;
}

void conn(int p, int q, int d)
{
	adj[p][an[p]] = q;
	adjd[p][an[p]++] = d;
}

void back(int cur, int first)
{
	if (cur < 0)
	{
		return;
	}
	back(from[cur], 0);
	printf("%d%c", cur>n?cur-n:cur, first?'\n':' ');
	if (cur > n && from[cur] <= n)
	{
		ex = from[cur];
	}
}

int main()
{
	int bl, ucnt, s, t, i, j, d, rt, p, q, m;
	bl = 0;
	ucnt = 0;
	while (scanf("%d%d%d", &n, &s, &t) == 3)
	{
		int n2 = (n << 1);
		scanf("%d", &m);
		memset(an, 0, sizeof(an));
		for (i=0; i<m; i++)
		{
			scanf("%d%d%d", &p, &q, &d);
			conn(p, q, d);
			conn(q, p, d);
			conn(p+n, q+n, d);
			conn(q+n, p+n, d);
		}
		scanf("%d", &exm);
		for (i=0; i<exm; i++)
		{
			scanf("%d%d%d", &p, &q, &d);
			conn(p, q+n, d);
			conn(q, p+n, d);
		}
		memset(dis, -1, sizeof(dis));
		heap[0].id = s;
		heap[0].dis = 0;
		hn = 1;
		dis[s] = 0;
		from[s] = -1;
		ucnt++;
		for (i=0; i<n2; i++)
		{
			int cur = -1;
			while (hn >= 0)
			{
				int nxt = heap[0].id;
				std::pop_heap(heap, heap+hn, comp);
				hn--;
				if (used[nxt] != ucnt)
				{
					cur = nxt;
					break;
				}
			}
			if (cur == -1)
			{
				break;
			}
			used[cur] = ucnt;
			for (j=0; j<an[cur]; j++)
			{
				int nxt = adj[cur][j];
				if (used[nxt] != ucnt)
				{
					d = adjd[cur][j];
					if (dis[nxt] < 0 || dis[cur] + d < dis[nxt])
					{
						dis[nxt] = dis[cur] + d;
						from[nxt] = cur;
						heap[hn].id = nxt;
						heap[hn].dis = dis[nxt];
						hn++;
						std::push_heap(heap, heap+hn, comp);
					}
				}
			}
		}
		rt = t;
		if (dis[rt] < 0 || dis[rt+n] < dis[rt])
		{
			rt = rt + n;
		}
		if (bl)
		{
			puts("");
		}
		bl = 1;
		back(rt, 1);
		if (rt > n)
		{
			printf("%d\n", ex);
		}
		else
		{
			puts("Ticket Not Used");
		}
		printf("%d\n", dis[rt]);
	}
	return 0;
}
