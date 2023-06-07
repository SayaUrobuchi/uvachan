#include <iostream>
using namespace std;

const int N = 200005;
const int N4 = (N << 2);
const int SWAP = 1;

int n;
int val[N];
int seg[N4], bonus[N4];
char s[N];

void push(int cur, int left, int right)
{
	int t = bonus[cur];
	bonus[left] += t;
	bonus[right] += t;
	seg[left] += t;
	seg[right] += t;
	bonus[cur] = 0;
}

void build(int cur, int l, int r)
{
	if (l == r)
	{
		seg[cur] = val[l];
		return;
	}
	int mid = ((l + r) >> 1);
	int left = (cur << 1);
	int right = (left | 1);
	build(left, l, mid);
	build(right, mid+1, r);
	seg[cur] = min(seg[left], seg[right]);
}

void fix(int cur, int l, int r, int ql, int qr, int d)
{
	if (l >= ql && r <= qr)
	{
		bonus[cur] += d;
		seg[cur] += d;
		return;
	}
	int mid = ((l + r) >> 1);
	int left = (cur << 1);
	int right = (left | 1);
	push(cur, left, right);
	if (ql <= mid)
	{
		fix(left, l, mid, ql, qr, d);
	}
	if (qr >= mid + 1)
	{
		fix(right, mid+1, r, ql, qr, d);
	}
	seg[cur] = min(seg[left], seg[right]);
}

int query(int cur, int l, int r, int ql, int qr)
{
	if (l >= ql && r <= qr)
	{
		return seg[cur];
	}
	int mid = ((l + r) >> 1);
	int left = (cur << 1);
	int right = (left | 1);
	push(cur, left, right);
	int res = 2e9;
	if (ql <= mid)
	{
		res = min(res, query(left, l, mid, ql, qr));
	}
	if (qr >= mid + 1)
	{
		res = min(res, query(right, mid+1, r, ql, qr));
	}
	return res;
}

void chg(int st, int ed)
{
	if (s[st] == '(')
	{
		fix(1, 1, n, st, ed-1, -2);
	}
	else
	{
		fix(1, 1, n, st, ed-1, 2);
	}
	swap(s[st], s[ed]);
}

int main()
{
	int m, i, cur;
	scanf("%d%d", &n, &m);
	scanf("%s", s+1);
	for (i=1, cur=0; i<=n; i++)
	{
		if (s[i] == '(')
		{
			++cur;
			val[i] = cur;
		}
		else
		{
			--cur;
			val[i] = cur;
		}
	}
	build(1, 1, n);
	for (i=0; i<m; i++)
	{
		int cmd, a, b;
		scanf("%d%d%d", &cmd, &a, &b);
		if (cmd == SWAP)
		{
			if (s[a] != s[b])
			{
				chg(a, b);
			}
		}
		else
		{
			bool ans = (s[a] == '(' && s[b] == ')');
			if (ans)
			{
				int l = query(1, 1, n, a, a);
				int r = query(1, 1, n, b, b);
				int total = query(1, 1, n, a, b);
				ans = (l == r+1 && total >= r);
			}
			puts(ans ? "Yes" : "No");
		}
	}
	return 0;
}
