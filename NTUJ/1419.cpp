#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int seg[300005], pre[1000005], ary[100005], s[100005], t[100005], a[100005];
vector<int> v[100005];

void ins(int *seg, int idx, int l, int r, int p, int q, int val)
{
	int c;
	if(l <= p && r >= q)
	{
		seg[idx] += val;
		return;
	}
	c = ((p+q)>>1);
	if(r >= p && c >= l)
	{
		ins(seg, idx<<1, l, r, p, c, val);
	}
	if(r >= c+1 && q >= l)
	{
		ins(seg, (idx<<1)+1, l, r, c+1, q, val);
	}
}

int qry(int *seg, int idx, int t, int p, int q)
{
	int c;
	if(p == q)
	{
		return seg[idx];
	}
	c = ((p+q)>>1);
	return seg[idx]+(t<=c?qry(seg, idx<<1, t, p, c):qry(seg, (idx<<1)+1, t, c+1, q));
}

int main()
{
	int count, n, i, j, k, p, q, u;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			pre[ary[i]] = n;
			v[i].clear();
		}
		scanf("%d", &q);
		for(i=0; i<q; i++)
		{
			scanf("%d%d", &s[i], &t[i]);
			v[s[i]-1].push_back(i);
		}
		memset(seg, 0, sizeof(seg));
		for(i=n-1; i>=0; i--)
		{
			u = ary[i];
			ins(seg, 1, i, pre[u]-1, 0, n-1, 1);
			pre[u] = i;
			for(j=0, k=v[i].size(); j<k; j++)
			{
				p = v[i][j];
				a[p] = qry(seg, 1, t[p]-1, 0, n-1);
			}
		}
		for(i=0; i<q; i++)
		{
			printf("%d\n", a[i]);
		}
	}
	return 0;
}
