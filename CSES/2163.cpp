#include <iostream>
using namespace std;

const int N = 262144;

int ary[N<<2], cnt[N<<2];

void build(int cur, int l, int r)
{
	if (l > r)
	{
		return;
	}
	int mid = ((l+r) >> 1);
	ary[cur] = mid;
	cnt[cur] = mid-l;
	build(cur<<1, l, mid-1);
	build((cur<<1)|1, mid+1, r);
}

int search(int cur, int tar)
{
	//printf(".. %d (%d) tar %d cnt %d\n", cur, ary[cur], tar, cnt[cur]);
	if (cnt[cur] == tar && ary[cur] > 0)
	{
		int res = ary[cur];
		ary[cur] = -1;
		return res;
	}
	if (cnt[cur] <= tar)
	{
		tar -= cnt[cur];
		if (ary[cur] > 0)
		{
			--tar;
		}
		return search((cur<<1)|1, tar);
	}
	--cnt[cur];
	return search((cur<<1), tar);
}

int main()
{
	int n, j, t, k;
	while (cin >> n >> k)
	{
		build(1, 1, n);
		for (j=k%n; n; j=(j+k)%n)
		{
			t = search(1, j);
			cout << t;
			if (--n)
			{
				cout << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}

