#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
using namespace std;

using mm = unordered_map<string, int>;

char buf[1048576];

int main()
{
	int t, u, i;
	bool first;
	string s;
	vector<string> v;
	mm var;
	while (getline(cin, s))
	{
		if (s == "0")
		{
			break;
		}
		if (sscanf(s.c_str(), "%s = %d", buf, &t) == 2)
		{
			var[buf] = t;
		}
		else
		{
			stringstream ss(s);
			t = 0;
			v.clear();
			while (ss >> s)
			{
				if (s[0] >= '0' && s[0] <= '9')
				{
					sscanf(s.c_str(), "%d", &u);
					t += u;
				}
				else
				{
					mm::iterator it = var.find(s);
					if (it == var.end())
					{
						v.emplace_back(s);
					}
					else
					{
						t += it->second;
					}
				}
				ss >> s;
			}
			//cout << "----------------------------- ";
			first = true;
			if (t || !v.size())
			{
				cout << t;
				first = false;
			}
			for (i=0; i<v.size(); i++)
			{
				if (!first)
				{
					cout << " + ";
				}
				first = false;
				cout << v[i];
			}
			cout << "\n";
		}
	}
	return 0;
}
