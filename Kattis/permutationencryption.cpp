#include <iostream>
using namespace std;

int ary[32];

int main()
{
	int n, i, j;
	string s, t;
	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}
		for (i=0; i<n; i++)
		{
			cin >> ary[i];
			--ary[i];
		}
		getline(cin, s);
		getline(cin, s);
		s.resize(s.size()+(n-s.size()%n)%n, ' ');
		t.resize(s.size());
		for (i=0; i<s.size(); i+=n)
		{
			for (j=0; j<n; j++)
			{
				t[i+j] = s[i+ary[j]];
			}
		}
		cout << "'" << t << "'\n";
	}
	return 0;
}
