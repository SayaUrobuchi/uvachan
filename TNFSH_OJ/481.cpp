#include <iostream>
#include <vector>
using namespace std;

const int N = 131072;

int price[N];
bool need[N];
vector<int> v[N];

long long recurs(int cur)
{
	int i;
	long long res, sum;
	if (need[cur])
	{
		return price[cur];
	}
	res = price[cur];
	for (i=0, sum=0; i<v[cur].size(); i++)
	{
		sum += recurs(v[cur][i]);
	}
	return min(res, sum);
}

int main()
{
	int n, m, i, t;
	while (cin >> n >> m)
	{
		for (i=0; i<n; i++)
		{
			v[i].clear();
			need[i] = false;
		}
		for (i=1; i<n; i++)
		{
			cin >> t;
			v[t].emplace_back(i);
		}
		for (i=0; i<n; i++)
		{
			cin >> price[i];
		}
		for (i=0; i<m; i++)
		{
			cin >> t;
			need[t] = true;
		}
		cout << recurs(0) << "\n";
	}
	return 0;
}
