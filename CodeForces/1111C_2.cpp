#include <stdio.h>
#include <vector>
using namespace std;

int a, b;

long long recurs(int p, int q, int d, vector<int> &v)
{
	int mid, i;
	long long res, res2;
	vector<int> lv, rv;
	if (!v.size())
	{
		return a;
	}
	if (p == q)
	{
		return b*v.size();
	}
	res = (long long)b*(q-p+1)*v.size();
	mid = ((p+q) >> 1);
	for (i=0; i<v.size(); i++)
	{
		if (v[i] & (1<<d))
		{
			rv.emplace_back(v[i]);
		}
		else
		{
			lv.emplace_back(v[i]);
		}
	}
	res2 = recurs(p, mid, d-1, lv) + recurs(mid+1, q, d-1, rv);
	//printf("%d %d %d %d => %lld %lld\n", p, q, r, s, res, res2);
	return res2<res ? res2 : res;
}

int main()
{
	int n, m, i;
	vector<int> v;
	while (scanf("%d%d%d%d", &m, &n, &a, &b) == 4)
	{
		v.resize(n);
		for (i=0; i<n; i++)
		{
			scanf("%d", &v[i]);
			--v[i];
		}
		printf("%lld\n", recurs(1, (1<<m), m-1, v));
	}
	return 0;
}
