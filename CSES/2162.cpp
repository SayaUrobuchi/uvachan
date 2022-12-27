#include <iostream>
#include <vector>
using namespace std;

int nxt[262144];

int main()
{
	int n, i, j;
	vector<int> v;
	while (cin >> n)
	{
		for (i=1; i<n; i++)
		{
			nxt[i] = i+1;
		}
		nxt[n] = 1;
		v.clear();
		for (i=1, j=0; j<n; j++, i=nxt[i])
		{
			v.emplace_back(nxt[i]);
			nxt[i] = nxt[nxt[i]];
		}
		cout << v[0];
		for (i=1; i<v.size(); i++)
		{
			cout << " " << v[i];
		}
		cout << "\n";
	}
	return 0;
}

