#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int LIM = 100000;

void divid(long long t, vector<int> &v)
{
	vector<int> u;
	for (int i=1; (long long)i*i<=t; i++)
	{
		if (t % i == 0 && i <= LIM && t/i <= LIM)
		{
			v.emplace_back(i);
			if (i * i != t)
			{
				u.emplace_back(t / i);
			}
		}
	}
	while (!u.empty())
	{
		v.emplace_back(u.back());
		u.pop_back();
	}
}

int main()
{
	int n;
	long long m;
	vector<int> v;
	vector<int> stk, idx;
	scanf("%d%lld", &n, &m);
	divid(m, v);
	stk.emplace_back(-1);
	idx.emplace_back(-1);
	long long ans = 0;
	for (int i=0, k=(int)v.size()-1; i<n; i++)
	{
		int t;
		scanf("%d", &t);
		while (stk.back() >= t)
		{
			stk.pop_back();
			idx.pop_back();
		}
		stk.emplace_back(t);
		idx.emplace_back(i);
		if (k >= 0 && i + 1 >= m / v[k])
		{
			--k;
		}
		int id = 0;
		for (int j=k+1; j<v.size()&&v[j]<=t; j++)
		{
			long long width = m / v[j];
			//printf("pos %d width %d:\n", i, width);
			id = upper_bound(idx.begin()+id, idx.end(), i-width) - idx.begin();
			//printf(".. %d (%d, %d) get %d (%d)\n", id, stk[id], idx[id], v[j], stk[id]-v[j]+1);
			ans += max(0, stk[id]-v[j]+1);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
