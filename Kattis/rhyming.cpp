#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;

int len[128], ac[128];
string ary[128][128];

bool ispost(const string &a, const string &b)
{
	if (a.size() < b.size())
	{
		return false;
	}
	return strncmp(a.c_str()+a.size()-b.size(), b.c_str(), b.size()) == 0;
}

int main()
{
	int n, m, i, j, k, t, u;
	bool ok;
	string common, s;
	while (cin >> common)
	{
		cin >> n;
		getline(cin, s);
		for (i=0, k=0; i<n; i++)
		{
			getline(cin, s);
			stringstream ss(s);
			for (j=0, ok=false; ss>>ary[i][j]; j++)
			{
				if (ispost(common, ary[i][j]))
				{
					ok = true;
				}
			}
			len[i] = j;
			if (ok)
			{
				ac[k++] = i;
			}
		}
		cin >> m;
		getline(cin, s);
		for (i=0; i<m; i++)
		{
			getline(cin, s);
			stringstream ss(s);
			while (ss>>s);
			for (j=0, ok=false; j<k&&!ok; j++)
			{
				t = ac[j];
				for (u=0; u<len[t]; u++)
				{
					if (ispost(s, ary[t][u]))
					{
						ok = true;
						break;
					}
				}
			}
			puts(ok?"YES":"NO");
		}
	}
	return 0;
}
