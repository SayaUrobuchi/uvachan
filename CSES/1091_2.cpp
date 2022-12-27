#include <iostream>
#include <algorithm>
using namespace std;

int ary[262144], par[262144];

int getpar(int cur)
{
	if (par[cur] < 0)
	{
		return cur;
	}
	return par[cur] = getpar(par[cur]);
}

int main()
{
	int n, m, i, j, k, t;
	while (cin >> n >> m)
	{
		for (i=0; i<n; i++)
		{
			cin >> ary[i];
			par[i] = -1;
		}
		sort(ary, ary+n);
		for (i=0; i<m; i++)
		{
			cin >> t;
			j = upper_bound(ary, ary+n, t) - ary;
			--j;
			if (j < 0)
			{
				cout << "-1\n";
				continue;
			}
			j = getpar(j);
			if (par[j] < -1)
			{
				cout << "-1\n";
				continue;
			}
			cout << ary[j] << "\n";
			k = -2;
			if (j)
			{
				k = getpar(j-1);
			}
			par[j] = k;
		}
	}
	return 0;
}

