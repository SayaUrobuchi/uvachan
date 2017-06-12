#include <stdio.h>
#include <string.h>

int map[2005][2005], mnum[2005];
int let[2005], lan[2005][2], len[2005];
int dis[2005], used[2005];
char s1[10005], s2[10005], s3[10005];

typedef struct data
{
	int node, dis;
}data;

typedef struct bst
{
	int id;
	struct bst *left, *right;
	char s[64];
}bst;

int ptt;
data pool[100000];

int hnum;
data *heap[100000];

int lan_id;
bst bst_pool[5000], *head;

bst *get_bst_pool()
{
	return bst_pool+lan_id++;
}

bst *find_lan(bst *ptr, char *s, int *res)
{
	int cmp;
	if(ptr == NULL)
	{
		ptr = get_bst_pool();
		ptr->id = lan_id;
		strcpy(ptr->s, s);
		ptr->left = ptr->right = NULL;
		*res = ptr->id;
		return ptr;
	}
	cmp = strcmp(ptr->s, s);
	if(cmp == 0)
	{
		*res = ptr->id;
	}
	else if(cmp > 0)
	{
		ptr->left = find_lan(ptr->left, s, res);
	}
	else
	{
		ptr->right = find_lan(ptr->right, s, res);
	}
	return ptr;
}

int get_lan(char *s)
{
	int res;
	head = find_lan(head, s, &res);
	return res;
}

void init_lan()
{
	lan_id = 0;
	head = NULL;
}

void init_pool()
{
	ptt = 0;
}

data *get_pool()
{
	return pool+ptt++;
}

void init_heap()
{
	hnum = 1;
}

int h_comp(int p, int q)
{
	return heap[p]->dis - heap[q]->dis;
}

void h_swap(int p, int q)
{
	data *t;
	t = heap[p];
	heap[p] = heap[q];
	heap[q] = t;
}

void heapdown(int now)
{
	int left, right;
	left = (now<<1);
	right = left+1;
	if(left < hnum)
	{
		if(right >= hnum || h_comp(left, right) < 0)
		{
			if(h_comp(left, now) < 0)
			{
				h_swap(left, now);
				heapdown(left);
			}
		}
		else
		{
			if(h_comp(right, now) < 0)
			{
				h_swap(right, now);
				heapdown(right);
			}
		}
	}
}

void heapup(int now)
{
	int par;
	par = (now>>1);
	if(par)
	{
		if(h_comp(par, now) > 0)
		{
			h_swap(par, now);
			heapup(par);
		}
	}
}

void h_push(data *t)
{
	heap[hnum++] = t;
	heapup(hnum-1);
}

data *h_pop()
{
	if(hnum == 1)
	{
		return NULL;
	}
	heap[0] = heap[1];
	heap[1] = heap[--hnum];
	heapdown(1);
	return heap[0];
}

int main()
{
	int n, i, j, p, nd, dd, nx;
	int st, ed, stlan, edlan;
	data *temp, *now;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		init_lan();
		scanf("%s%s", s1, s2);
		stlan = get_lan(s1);
		edlan = get_lan(s2);
		memset(mnum, 0, sizeof(mnum));
		lan[0][0] = lan[0][1] = stlan;
		let[0] = -1;
		len[0] = 0;
		lan[1][0] = lan[1][1] = edlan;
		let[1] = -2;
		len[1] = 0;
		st = 0;
		ed = 1;
		for(i=0; i<n; i++)
		{
			scanf("%s%s%s", s1, s2, s3);
			p = i+2;
			let[p] = *s3;
			lan[p][0] = get_lan(s1);
			lan[p][1] = get_lan(s2);
			len[p] = strlen(s3);
			for(j=p-1; j>=0; j--)
			{
				if(let[p] != let[j])
				{
					if(lan[p][0] == lan[j][0] || lan[p][1] == lan[j][0] || lan[p][0] == lan[j][1] || lan[p][1] == lan[j][1])
					{
						map[p][mnum[p]] = j;
						mnum[p]++;
						map[j][mnum[j]] = p;
						mnum[j]++;
					}
				}
			}
		}
		init_pool();
		init_heap();
		temp = get_pool();
		temp->node = st;
		temp->dis = 0;
		for(i=0; i<n+2; i++)
		{
			dis[i] = 1000000000;
		}
		dis[st] = 0;
		h_push(temp);
		memset(used, 0, sizeof(used));
		used[st] = 1;
		while(now=h_pop())
		{
			nd = now->node;
			dd = now->dis;
			if(dd != dis[nd])
			{
				continue;
			}
			used[nd] = 1;
			if(nd == ed)
			{
				break;
			}
			for(i=0; i<mnum[nd]; i++)
			{
				nx = map[nd][i];
				if(used[nx] == 0 && dis[nx] > dd + len[nx])
				{
					dis[nx] = dd + len[nx];
					temp = get_pool();
					temp->node = nx;
					temp->dis = dis[nx];
					h_push(temp);
				}
			}
		}
		if(used[ed])
		{
			printf("%d\n", dis[ed]);
		}
		else
		{
			printf("impossivel\n");
		}
	}
	return 0;
}
