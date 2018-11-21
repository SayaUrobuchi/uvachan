#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ans1, ans2;
int par[100005], cnt[100005], nor[100005], sou[100005];
int type[200005], a[200005], b[200005], c[200005];
int used[1000005], has[1000005];
int ary[300005], t1[1000005], t2[1000005];
char buf[100005];

int comp(const void *p, const void *q)
{
	return *(int*)p-*(int*)q;
}

int get_par(int now)
{
	if(now == par[now])
	{
		return now;
	}
	return par[now] = get_par(par[now]);
}

void add(int ptr, int lb, int rb, int l, int r, int v1, int v2)
{
	int mid;
	if(l <= lb && r >= rb)
	{
		t1[ptr] += v1;
		t2[ptr] += v2;
		return;
	}
	mid = ((lb+rb)>>1);
	if(l <= mid)
	{
		add((ptr<<1), lb, mid, l, r, v1, v2);
	}
	if(r >= mid+1)
	{
		add((ptr<<1)+1, mid+1, rb, l, r, v1, v2);
	}
}

void ask(int ptr, int lb, int rb, int tar)
{
	int mid;
	ans1 += t1[ptr];
	ans2 += t2[ptr];
	if(lb == rb)
	{
		return;
	}
	mid = ((lb+rb)>>1);
	if(tar <= mid)
	{
		ask((ptr<<1), lb, mid, tar);
	}
	if(tar >= mid+1)
	{
		ask((ptr<<1)+1, mid+1, rb, tar);
	}
}

int main()
{
	int count, n, m, i, j, p, q, loc;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0, j=0; i<n; i++)
		{
			scanf("%*d%d", &loc);
			par[i] = i;
			cnt[i] = 1;
			nor[i] = loc;
			sou[i] = loc;
		}
		scanf("%d", &m);
		for(i=0; i<m; i++)
		{
			scanf("%s", buf);
			if(*buf == 'r')
			{
				type[i] = 0;
				scanf("%d%d", &a[i], &b[i]);
				if(used[nor[a[i]]] != count+1)
				{
					used[nor[a[i]]] = count+1;
					ary[j++] = nor[a[i]];
				}
				if(used[nor[b[i]]] != count+1)
				{
					used[nor[b[i]]] = count+1;
					ary[j++] = nor[b[i]];
				}
			}
			else
			{
				type[i] = 1;
				scanf("%d.5", &c[i]);
				if(used[c[i]] != count+1)
				{
					used[c[i]] = count+1;
					ary[j++] = c[i];
				}
			}
		}
		qsort(ary, j, sizeof(int), comp);
		for(i=0; i<j; i++)
		{
			has[ary[i]] = i;
		}
		for(i=0; i<n; i++)
		{
			sou[i] = has[sou[i]];
			nor[i] = has[nor[i]];
		}
		memset(t1, 0, sizeof(t1));
		memset(t2, 0, sizeof(t2));
		for(i=0; i<m; i++)
		{
			if(type[i])
			{
				ans1 = 0;
				ans2 = 0;
				ask(1, 0, j-1, has[c[i]]);
				printf("%d %d\n", ans1, ans2);
			}
			else
			{
				p = get_par(a[i]);
				q = get_par(b[i]);
				if(p != q)
				{
					if(sou[p] < nor[p])
					{
						add(1, 0, j-1, sou[p], nor[p]-1, -1, -cnt[p]);
					}
					if(sou[q] < nor[q])
					{
						add(1, 0, j-1, sou[q], nor[q]-1, -1, -cnt[q]);
					}
					par[p] = q;
					cnt[q] += cnt[p];
					if(sou[p] < sou[q])
					{
						sou[q] = sou[p];
					}
					if(nor[p] > nor[q])
					{
						nor[q] = nor[p];
					}
					if(sou[q] < nor[q])
					{
						add(1, 0, j-1, sou[q], nor[q]-1, 1, cnt[q]);
					}
				}
			}
		}
	}
	return 0;
}
