#include <iostream>
#include <sstream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> tbl;

int main()
{
	int i;
	string s, t, u;
	bool first;
	while (getline(cin, s))
	{
		stringstream ss(s);
		first = true;
		while (ss >> t)
		{
			u = t;
			for (i=0; i<u.size(); i++)
			{
				u[i] |= 32;
			}
			if (!first)
			{
				cout << " ";
			}
			first = false;
			if (tbl[u])
			{
				cout << ".";
			}
			else
			{
				cout << t;
				tbl[u] = 1;
			}
		}
		cout << "\n";
	}
	return 0;
}
