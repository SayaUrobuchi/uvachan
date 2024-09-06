#include <iostream>
#include <vector>
using namespace std;

int recurs(const vector<int> &v)
{
	int i;
	vector<int> u[2];
	int ret = 1;
	if (v.size() == 1)
	{
		return ret;
	}
	int a = 0, b = 1;
	for (i=0; i<v.size(); i++)
	{
		u[i&1].emplace_back(v[i]);
		a |= v[i];
		b &= v[i];
	}
	if (a+b == 1)
	{
		ret += recurs(u[0]) + recurs(u[1]);
	}
	return ret;
}

int main()
{
	int n, i, t;
	vector<int> v;
	scanf("%d", &n);
	for (i=0; i<(1<<n); i++)
	{
		scanf("%d", &t);
		v.emplace_back(t);
	}
	int ans = recurs(v);
	printf("%d\n", ans);
	return 0;
}