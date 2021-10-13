#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int ary[1048576], cry[1048576];
pair<int, int> bry[1048576];
int seg[1048576<<2];

void chg(int idx, int l, int r, int pos, int val)
{
	int m = ((l+r) >> 1);
	if (l == r)
	{
		seg[idx] = val;
		return;
	}
	if (pos <= m)
	{
		chg(idx<<1, l, m, pos, val);
	}
	else
	{
		chg((idx<<1)|1, m+1, r, pos, val);
	}
	seg[idx] = max(seg[idx<<1], seg[(idx<<1)|1]);
}

int query(int idx, int l, int r, int ql, int qr)
{
	if (ql <= l && qr >= r)
	{
		return seg[idx];
	}
	int res = -2147483647;
	int m = ((l+r)>>1);
	if (ql <= m)
	{
		res = max(res, query(idx<<1, l, m, ql, qr));
	}
	if (qr >= m+1)
	{
		res = max(res, query((idx<<1)|1, m+1, r, ql, qr));
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, i, j, t;
	while (cin >> n >> m)
	{
		for (i=0; i<n; i++)
		{
			cin >> ary[i];
			bry[i] = {ary[i], i};
		}
		sort(bry, bry+n);
		memset(seg, 0, sizeof(seg));
		for (i=0; i<n; )
		{
			for (j=i+1; j<n&&bry[j].first==bry[j-1].first&&bry[j].second-bry[j-1].second<=m-1; j++);
			t = query(1, 0, n-1, bry[i].second-(m-1), bry[j-1].second+(m-1)) + 1;
			for (; i<j; i++)
			{
				cry[bry[i].second] = t;
				chg(1, 0, n-1, bry[i].second, t);
			}
		}
		cout << cry[0];
		for (i=1; i<n; i++)
		{
			cout << " " << cry[i];
		}
		cout << " \n";
	}
	return 0;
}
