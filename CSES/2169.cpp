#include <iostream>
#include <algorithm>
using namespace std;
using pp = pair<pair<int, int>, int>;
const int N = 262144;
const int N4 = (N<<2);

int atk[N], def[N];
int cnt[N4], laz[N4];
pp bry[N], val[N4];
pp ary[N];
bool stat[N4];

bool comp(const pp &a, const pp &b)
{
	if (a.first.first == b.first.first)
	{
		return a.first.second > b.first.second;
	}
	return a.first.first < b.first.first;
}

void build(int cur, int l, int r)
{
	if (l > r)
	{
		return;
	}
	int mid = ((l+r) >> 1);
	val[cur] = bry[mid];
	cnt[cur] = 0;
	stat[cur] = 0;
	laz[cur] = 0;
	build(cur<<1, l, mid-1);
	build((cur<<1)|1, mid+1, r);
}

int ins(const int cur, const pp &tar)
{
	int ll = (cur << 1);
	int rr = (ll | 1);
	if (stat[cur])
	{
		atk[val[cur].second] += laz[cur];
	}
	laz[ll] += laz[cur];
	laz[rr] += laz[cur];
	laz[cur] = 0;
	if (val[cur] == tar)
	{
		stat[cur] = true;
		++laz[rr];
		return cnt[cur] + 1;
	}
	if (tar < val[cur])
	{
		++cnt[cur];
		++laz[rr];
		if (stat[cur])
		{
			++atk[val[cur].second];
		}
		return ins(ll, tar);
	}
	return ins(rr, tar) + cnt[cur] + stat[cur];
}

void travel(int cur)
{
	if (!stat[cur])
	{
		return;
	}
	int ll = (cur << 1);
	int rr = (ll | 1);
	atk[val[cur].second] += laz[cur];
	laz[ll] += laz[cur];
	laz[rr] += laz[cur];
	travel(ll);
	travel(rr);
}

int main()
{
	int n, i;
	while (cin >> n)
	{
		for (i=0; i<n; i++)
		{
			cin >> ary[i].first.first >> ary[i].first.second;
			ary[i].second = i;
			bry[i] = {{ary[i].first.second, -ary[i].first.first}, ary[i].second};
			def[i] = atk[i] = 0;
		}
		sort(ary, ary+n, comp);
		sort(bry, bry+n);
		build(1, 0, n-1);
		for (i=0; i<n; i++)
		{
			pp tar = make_pair(make_pair(ary[i].first.second, -ary[i].first.first), ary[i].second);
			def[ary[i].second] += i+1 - ins(1, tar);
		}
		travel(1);
		cout << atk[0];
		for (i=1; i<n; i++)
		{
			cout << " " << atk[i];
		}
		cout << "\n";
		cout << def[0];
		for (i=1; i<n; i++)
		{
			cout << " " << def[i];
		}
		cout << "\n";
	}
	return 0;
}

