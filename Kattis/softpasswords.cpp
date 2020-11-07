#include <iostream>
using namespace std;

string rev(string s)
{
	int i;
	for (i=0; i<s.size(); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] -= 32;
		}
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] |= 32;
		}
	}
	return s;
}

int main()
{
	string s, p;
	while (cin >> s >> p)
	{
		if (s == p || (s[0] >= '0' && s[0] <= '9' && s[0]+p == s)
			|| (s.back() >= '0' && s.back() <= '9' && p+s.back() == s) || rev(p) == s)
		{
			puts("Yes");
		}
		else
		{
			puts("No");
		}
	}
	return 0;
}
