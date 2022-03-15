#include <iostream>
#include <algorithm>
using namespace std;

int ary[262144], idx[262144];

bool comp(const int &a, const int &b)
{
	return ary[a] < ary[b];
}

int main()
{
	int n, i, t;
	long long m, u;
	while (scanf("%d%lld", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			idx[i] = i;
		}
		nth_element(idx, idx+(m%n), idx+n, comp);
		t = ary[idx[m%n]];
		u = m / n;
		for (i=0; i<n; i++)
		{
			printf("%lld\n", u+(ary[i]<t));
		}
	}
	return 0;
}
