#include <iostream>
#include <algorithm>
using namespace std;
using frac_t = pair<int, int>;
using seg_t = pair<frac_t, frac_t>;

const int N = 1000000005;

seg_t ary[200005];

frac_t calc(int x, int y)
{
	return make_pair(x, y);
}

int fcomp(const frac_t &a, const frac_t &b)
{
	// a.f/a.s < b.f/b.s
	// a.f*b.s < b.f*a.s
	if ((long long)a.first*b.second < (long long)b.first*a.second)
	{
		return -1;
	}
	if ((long long)a.first*b.second > (long long)b.first*a.second)
	{
		return 1;
	}
	return 0;
}

bool comp(const seg_t &a, const seg_t &b)
{
	return fcomp(a.first, b.first) < 0;
}

int main()
{
	int n, i, a, b, ans;
	frac_t last;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d%d", &a, &b);
		ary[i].first = calc(a-1, b);
		ary[i].second = calc(a, b-1);
	}
	sort(ary, ary+n, comp);
	for (i=0, ans=0, last=make_pair(0, 1); i<n; i++)
	{
		if (fcomp(ary[i].first, last) >= 0)
		{
			++ans;
			last = ary[i].second;
		}
		else if (fcomp(ary[i].second, last) < 0)
		{
			last = ary[i].second;
		}
	}
	printf("%d\n", ans);
	return 0;
}
