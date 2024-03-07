#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, i;
	scanf("%d", &n);
	vector<int> v;
	for (i=0; i<n; i++)
	{
		int t;
		scanf("%d", &t);
		decltype(v)::iterator it = lower_bound(v.begin(), v.end(), t);
		if (it == v.end())
		{
			v.emplace_back(t);
		}
		else
		{
			*it = t;
		}
	}
	printf("%d\n", (int)v.size());
	return 0;
}