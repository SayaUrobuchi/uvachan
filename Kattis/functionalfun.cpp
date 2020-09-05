#include <iostream>
#include <sstream>
#include <map>
using namespace std;

map<string, int> dom, cod;
bool domu[1048576], codu[1048576];

void read(string &s, map<string, int> &m)
{
	int i;
	stringstream ss(s);
	string t;
	m.clear();
	ss >> t;
	i = 0;
	while (ss >> t)
	{
		m[t] = i++;
	}
}

int main()
{
	int n, i, domn, codn, a, b;
	bool domg, codg, inj, sur;
	string s, t, garbage;
	while (getline(cin, s))
	{
		read(s, dom);
		getline(cin, s);
		read(s, cod);
		for (i=0; i<dom.size(); i++)
		{
			domu[i] = false;
		}
		for (i=0; i<cod.size(); i++)
		{
			codu[i] = false;
		}
		cin >> n;
		domg = false;
		codg = false;
		for (i=0, domn=0, codn=0; i<n; i++)
		{
			cin >> s >> garbage >> t;
			a = dom[s];
			b = cod[t];
			if (!domu[a])
			{
				domu[a] = true;
				++domn;
			}
			else
			{
				domg = true;
			}
			if (!codu[b])
			{
				codu[b] = true;
				++codn;
			}
			else
			{
				codg = true;
			}
		}
		if (domg)
		{
			cout << "not a function\n";
		}
		else
		{
			inj = !codg;
			sur = (codn == cod.size());
			//cout << "salkfjsa;lgjhaskjilgai;jgfa;ji " << codn << "/" << cod.size() << "\n";
			if (inj && sur)
			{
				cout << "bijective\n";
			}
			else if (inj)
			{
				cout << "injective\n";
			}
			else if (sur)
			{
				cout << "surjective\n";
			}
			else
			{
				cout << "neither injective nor surjective\n";
			}
		}
		getline(cin, s);
	}
	return 0;
}
