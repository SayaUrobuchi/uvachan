#include <iostream>
using namespace std;

int main()
{
	int i, cnt, pos;
	string s, t;
	pos = 0;
	while (getline(cin, s))
	{
		if (s.empty())
		{
			pos = 0;
			continue;
		}
		for (i=0, cnt=0; i<s.size(); i++)
		{
			if (s[i] == '*')
			{
				++cnt;
			}
		}
		string t;
		t.resize(s.size(), '.');
		for (i=s.size()-pos-cnt; i<s.size()-pos; i++)
		{
			t[i] = '*';
		}
		cout << t << "\n";
		pos += cnt;
	}
	return 0;
}
