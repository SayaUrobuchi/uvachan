#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 32768;
const int K = 5000;

int seg[N], add[N];
vector<int> v[8196];

void update(int cur, int l, int r, int ql, int qr, int val)
{
	int left, right, mid;
	left = (cur<<1);
	right = (left|1);
	if (ql <= l && qr >= r)
	{
		add[cur] += val;
		seg[cur] = max(seg[left], seg[right]) + add[cur];
		return;
	}
	mid = ((l+r) >> 1);
	if (ql <= mid)
	{
		update(left, l, mid, ql, qr, val);
	}
	if (qr >= mid+1)
	{
		update(right, mid+1, r, ql, qr, val);
	}
	seg[cur] = max(seg[left], seg[right]) + add[cur];
}

int query(int cur, int l, int r, int ql, int qr)
{
	int left, right, mid, t;
	left = (cur<<1);
	right = (left|1);
	if (ql <= l && qr >= r)
	{
		return seg[cur];
	}
	t = 0;
	mid = ((l+r) >> 1);
	if (ql <= mid)
	{
		t = max(t, query(left, l, mid, ql, qr));
	}
	if (qr >= mid+1)
	{
		t = max(t, query(right, mid+1, r, ql, qr));
	}
	return t + add[cur];
}

int main()
{
	int n, m, i, j, k, a, b, t, ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=1; i<=K; i++)
		{
			v[i].clear();
		}
		memset(seg, 0, sizeof(seg));
		memset(add, 0, sizeof(add));
		for (i=0; i<n; i++)
		{
			scanf("%d%d", &a, &b);
			v[a].emplace_back(b);
		}
		for (j=1, i=j-m, ans=1; j<=K; i++, j++)
		{
			for (k=0; k<v[j].size(); k++)
			{
				t = v[j][k];
				a = max(1, t-m);
				b = t;
				update(1, 1, K, a, b, 1);
			}
			ans = max(ans, query(1, 1, K, 1, K));
			if (i >= 1)
			{
				for (k=0; k<v[i].size(); k++)
				{
					t = v[i][k];
					a = max(1, t-m);
					b = t;
					update(1, 1, K, a, b, -1);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
