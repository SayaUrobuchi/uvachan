#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1048576;

int ary[N], lb[N], rb[N];
pair<int, int> bry[N];
long long ll[N], rr[N];

int main()
{
	int n, i, j, v, t;
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (cin >> n)
	{
		for (i=1; i<=n; i++)
		{
			cin >> ary[i];
			bry[i-1] = {ary[i], i};
			ll[i] = rr[i] = 0;
			lb[i] = i-1;
			rb[i] = i+1;
		}
		ary[0] = ary[n+1] = 2e9;
		sort(bry, bry+n);
		for (i=0; i<n; i++)
		{
			v = bry[i].first;
			t = bry[i].second;
			for (j=lb[t]; ary[j]<v; j=lb[j])
			{
				ll[t] += ll[j] + ary[j];
			}
			lb[t] = j;
			for (j=rb[t]; ary[j]<v; j=rb[j])
			{
				rr[t] += rr[j] + ary[j];
			}
			rb[t] = j;
		}
		for (i=1; i<=n; i++)
		{
			cout << ll[i]+rr[i] << "\n";
		}
	}
	return 0;
}
