#include <iostream>
#include <algorithm>
using namespace std;

string str[1024];
vector<string> v;

int main()
{
	int n, i, j, best;
	while (cin >> n)
	{
		for (i=0; i<n; i++)
		{
			cin >> str[i];
		}
		sort(str, str+n);
		v.clear();
		for (i=0, best=n+n; i<n; i=j)
		{
			for (j=i+1; j<n&&str[i]==str[j]; j++);
			if (j-i < best)
			{
				best = j-i;
				v.clear();
				v.emplace_back(str[i]);
			}
			else if (j-i == best)
			{
				v.emplace_back(str[i]);
			}
		}
		for (i=0; i<v.size(); i++)
		{
			cout << v[i] << "\n";
		}
	}
	return 0;
}
