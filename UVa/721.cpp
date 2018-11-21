#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct __node
{
	int n;
	long long dis;
}node;

int hn;
int used[1000005];
long long dis[1000005];
node hpool[2000005], *hpt, *heap[2000005];
vector<node> conn[1000005], conn2[1000005];

void heap_up(int now)
{
	int par;
	node *temp;
	while(now > 1)
	{
		par = (now>>1);
		if(heap[now]->dis < heap[par]->dis)
		{
			temp = heap[now];
			heap[now] = heap[par];
			heap[par] = temp;
			now = par;
		}
		else
		{
			break;
		}
	}
}

void heap_down(int now)
{
	int left, right;
	node *temp;
	while(1)
	{
		left = (now<<1);
		right = left+1;
		if(left > hn)
		{
			break;
		}
		if(right > hn || (heap[left]->dis < heap[right]->dis))
		{
			if(heap[left]->dis < heap[now]->dis)
			{
				temp = heap[left];
				heap[left] = heap[now];
				heap[now] = temp;
				now = left;
			}
			else
			{
				break;
			}
		}
		else
		{
			if(heap[right]->dis < heap[now]->dis)
			{
				temp = heap[right];
				heap[right] = heap[now];
				heap[now] = temp;
				now = right;
			}
			else
			{
				break;
			}
		}
	}
}

void heap_push(int n, int d)
{
	node *temp;
	temp = hpt++;
	temp->n = n;
	temp->dis = d;
	heap[++hn] = temp;
	heap_up(hn);
}

node *heap_pop()
{
	if(hn == 0)
	{
		return NULL;
	}
	heap[0] = heap[1];
	heap[1] = heap[hn--];
	heap_down(1);
	return heap[0];
}

void dijkstra_heap(vector<node> *conn, int n, long long *dis, int st, int ed)
{
	node *temp;
	int now, tar, i, j;
	long long d, dd;
	memset(dis, -1, sizeof(*dis)*(n+1));
	memset(used, 0, sizeof(used));
	hn = 0;
	hpt = hpool;
	heap_push(st, 0);
	dis[st] = 0;
	while(1)
	{
		temp = heap_pop();
		if(temp == NULL)
		{
			break;
		}
		now = temp->n;
		if(temp->dis != dis[now])
		{
			continue;
		}
		used[now] = 1;
		if(now == ed)
		{
			break;
		}
		d = temp->dis;
		for(i=0, j=conn[now].size(); i<j; i++)
		{
			tar = conn[now][i].n;
			dd = conn[now][i].dis;
			if(used[tar] == 0 && (dis[tar] == -1 || dis[tar] > d+dd))
			{
				dis[tar] = d+dd;
				heap_push(tar, dis[tar]);
			}
		}
	}
}

int main()
{
	int count, n, m, i, p, q, d;
	long long ans;
	node temp;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		for(i=0; i<n; i++)
		{
			conn[i].clear();
			conn2[i].clear();
		}
		for(i=0; i<m; i++)
		{
			scanf("%d%d%d", &p, &q, &d);
			p--;
			q--;
			temp.n = q;
			temp.dis = d;
			conn[p].push_back(temp);
			temp.n = p;
			conn2[q].push_back(temp);
		}
		ans = 0;
		dijkstra_heap(conn, n, dis, 0, -1);
		for(i=0; i<n; i++)
		{
			ans += dis[i];
		}
		dijkstra_heap(conn2, n, dis, 0, -1);
		for(i=0; i<n; i++)
		{
			ans += dis[i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
