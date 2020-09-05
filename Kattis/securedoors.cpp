#include <iostream>
#include <map>
using namespace std;

string key[] = {"exited", "entered", "exited"};
map<string, int> m;

int main()
{
	int n, i, nxt;
	string s, t;
	while (cin >> n)
	{
		m.clear();
		for (i=0; i<n; i++)
		{
			cin >> s >> t;
			nxt = 0;
			if (s.size() == 5)
			{
				nxt = 1;
			}
			cout << t << " " << key[nxt];
			if (m[t] == nxt)
			{
				cout << " (ANOMALY)";
			}
			cout << "\n";
			m[t] = nxt;
		}
	}
	return 0;
}
