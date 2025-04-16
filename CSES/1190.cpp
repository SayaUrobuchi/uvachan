#include <iostream>
using namespace std;
 
const int N = 200005;
const int N4 = (N << 2);
 
int ary[N];
long long pre[N];
long long mx[N4], mn[N4], res[N4], flag[N4];
 
void build(int l, int r, int cur, long long ary[])
{
	if (l == r)
	{
		mx[cur] = mn[cur] = ary[l];
		res[cur] = 0;
		return;
	}
	int mid = ((l + r) >> 1);
	int lp = (cur << 1);
	int rp = (lp | 1);
	build(l, mid, lp, ary);
	build(mid+1, r, rp, ary);
	mx[cur] = max(mx[lp], mx[rp]);
	mn[cur] = min(mn[lp], mn[rp]);
	res[cur] = max(res[lp], res[rp]);
	res[cur] = max(res[cur], mx[rp]-mn[lp]);
}
 
void push(int par, int child)
{
	mx[child] += flag[par];
	mn[child] += flag[par];
	flag[child] += flag[par];
}
 
void update(int l, int r, int cur, int ql, int qr, int d)
{
	if (ql <= l && qr >= r)
	{
		mx[cur] += d;
		mn[cur] += d;
		flag[cur] += d;
		return;
	}
	int mid = ((l + r) >> 1);
	int lp = (cur << 1);
	int rp = (lp | 1);
	push(cur, lp);
	push(cur, rp);
	flag[cur] = 0;
	if (ql <= mid)
	{
		update(l, mid, lp, ql, qr, d);
	}
	if (qr >= mid+1)
	{
		update(mid+1, r, rp, ql, qr, d);
	}
	mx[cur] = max(mx[lp], mx[rp]);
	mn[cur] = min(mn[lp], mn[rp]);
	res[cur] = max(res[lp], res[rp]);
	res[cur] = max(res[cur], mx[rp]-mn[lp]);
}
 
int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[i]);
		pre[i] = pre[i-1] + ary[i];
	}
	build(0, n, 1, pre);
	for (i=0; i<m; i++)
	{
		int pos, val;
		scanf("%d%d", &pos, &val);
		int dif = val - ary[pos];
		ary[pos] = val;
		update(0, n, 1, pos, n, dif);
		long long ans = res[1];
		printf("%lld\n", ans);
	}
	return 0;
}
