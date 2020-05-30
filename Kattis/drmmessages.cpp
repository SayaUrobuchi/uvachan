#include <iostream>
using namespace std;

int n;

void rot(string &s, int st)
{
	int i, ed, sum;
	ed = st + n;
	for (i=st, sum=0; i<ed; i++)
	{
		sum += s[i] - 'A';
	}
	for (i=st; i<ed; i++)
	{
		s[i] = (s[i]-'A'+sum)%26 + 'A';
	}
}

int main()
{
	int i;
	string s;
	while (getline(cin, s))
	{
		n = (s.size()>>1);
		rot(s, 0);
		rot(s, n);
		for (i=0; i<n; i++)
		{
			s[i] = (s[i]-'A'+s[i+n]-'A')%26 + 'A';
		}
		s.resize(n);
		cout << s << "\n";
	}
	return 0;
}
