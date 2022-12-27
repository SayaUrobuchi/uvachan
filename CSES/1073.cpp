#include <iostream>
#include <algorithm>
using namespace std;

int ary[262144];

int main()
{
	int n, m, i, t, u;
	while (cin >> n)
	{
		for (i=0, m=0; i<n; i++)
		{
			cin >> t;
			u = upper_bound(ary, ary+m, t) - ary;
			if (u == m)
			{
				++m;
			}
			ary[u] = t;
		}
		cout << m << "\n";
	}
	return 0;
}

