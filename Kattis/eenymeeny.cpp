#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<string> v, res[2];

int main()
{
	int n, i, j, k;
	string s;
	while (getline(cin, s))
	{
		stringstream ss(s);
		k = 0;
		while (ss >> s)
		{
			++k;
		}
		cin >> n;
		v.resize(n);
		for (i=0; i<n; i++)
		{
			cin >> v[i];
		}
		res[0].clear();
		res[1].clear();
		for (i=0, j=0; i<n; i++)
		{
			j = (j+k-1) % v.size();
			res[i&1].emplace_back(v[j]);
			v.erase(v.begin()+j);
		}
		for (i=0; i<2; i++)
		{
			cout << res[i].size() << "\n";
			for (j=0; j<res[i].size(); j++)
			{
				cout << res[i][j] << "\n";
			}
		}
		getline(cin, s);
	}
	return 0;
}
