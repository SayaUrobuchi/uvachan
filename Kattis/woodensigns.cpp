#include<iostream>
#include <unordered_map>
using namespace std;
using ss = unordered_map<int, long long>;

const long long M = 2147483647;

int main()
{
	int n, m, i, t, x, y;
	long long ans;
	ss v0, v1;
	while (scanf("%d%d", &n, &m) == 2)
	{
		v0.clear();
		v0[m] = 1;
		v1.clear();
		for (i=0; i<n; i++)
		{
			scanf("%d", &t);
			for (ss::iterator it=v0.begin(); it!=v0.end(); ++it)
			{
				x = it->first;
				y = m;
				if (x > y)
				{
					swap(x, y);
				}
				if (t > x)
				{
					v1[x] += it->second;
					v1[x] %= M;
				}
				if (t < y)
				{
					v1[y] += it->second;
					v1[y] %= M;
				}
			}
			m = t;
			swap(v0, v1);
			v1.clear();
		}
		ans = 0;
		for (ss::iterator it=v0.begin(); it!=v0.end(); ++it)
		{
			ans = (ans+it->second) % M;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
