#include<iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

struct hnode
{
	int dis, id;
};

const int N = 10005;
const int HN = 128;

int hn;
int htbl[N];
int hotel[HN];
int dis[N];
int used[HN], qq[HN], qs[HN];

struct hnode heap[N<<1];

vector<int> hcc[HN];
vector<int> conn[N], cost[N];

bool hcomp(struct hnode p, struct hnode q)
{
	return p.dis > q.dis;
}

int main() {
	int n, i, h, m, p, q, c, d, cur, nxt, nd, cnt, j, k, s;
	cnt = 0;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		scanf("%d", &h);
		memset(htbl, -1, sizeof(htbl));
		hotel[0] = 1;
		htbl[1] = 0;
		hcc[0].clear();
		for (i=1; i<=h; i++)
		{
			scanf("%d", &hotel[i]);
			htbl[hotel[i]] = i;
			hcc[i].clear();
		}
		hotel[h+1] = n;
		hcc[h+1].clear();
		htbl[n] = h + 1;
		h += 2;
		for (i=1; i<=n; i++)
		{
			conn[i].clear();
			cost[i].clear();
		}
		scanf("%d", &m);
		for (i=0; i<m; i++)
		{
			scanf("%d%d%d", &p, &q, &c);
			conn[p].push_back(q);
			conn[q].push_back(p);
			cost[p].push_back(c);
			cost[q].push_back(c);
		}
		for (i=0; i<h; i++)
		{
			hn = 1;
			heap[0].dis = 0;
			heap[0].id = hotel[i];
			memset(dis, -1, sizeof(dis));
			dis[hotel[i]] = 0;
			while (hn > 0)
			{
				cur = heap[0].id;
				d = heap[0].dis;
				pop_heap(heap, heap+hn, hcomp);
				hn--;
				if (d == dis[cur])
				{
					if (htbl[cur] >= 0)
					{
						hcc[i].push_back(htbl[cur]);
					}
					for (j=0; j<conn[cur].size(); j++)
					{
						nxt = conn[cur][j];
						nd = d + cost[cur][j];
						if (nd <= 600 && (dis[nxt] == -1 || dis[nxt] > nd))
						{
							dis[nxt] = nd;
							heap[hn].dis = nd;
							heap[hn].id = nxt;
							push_heap(heap, heap+hn, hcomp);
							hn++;
						}
					}
				}
			}
		}
		cnt++;
		qq[0] = 0;
		qs[0] = 0;
		used[0] = cnt;
		for (i=0, j=1; i<j; i++)
		{
			cur = qq[i];
			s = qs[i];
			if (cur == h-1)
			{
				break;
			}
			if (cur)
			{
				s++;
			}
			for (k=0; k<hcc[cur].size(); k++)
			{
				nxt = hcc[cur][k];
				if (used[nxt] != cnt)
				{
					used[nxt] = cnt;
					qq[j] = nxt;
					qs[j] = s;
					j++;
				}
			}
		}
		if (i >= j)
		{
			puts("-1");
		}
		else
		{
			printf("%d\n", s);
		}
	}
	return 0;
}

