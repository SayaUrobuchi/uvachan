#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

int par[256];

int main()
{
	int cur, t, u;
	string s;
	cin >> t;
	getline(cin, s);
	memset(par, -1, sizeof(par));
	while (getline(cin, s))
	{
		if (s == "-1")
		{
			break;
		}
		stringstream ss(s);
		ss >> cur;
		while (ss >> u)
		{
			par[u] = cur;
		}
	}
	cout << t;
	for (t=par[t]; t!=-1; t=par[t])
	{
		cout << " " << t;
	}
	cout << "\n";
	return 0;
}
