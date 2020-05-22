#include <iostream>
using namespace std;

int main()
{
	string s, t;
	int i;
	while (cin >> s >> t)
	{
		i = s.size()-1;
		if (s[i] == 'x' && s[i-1] == 'e')
		{
			cout << s << t << "\n";
		}
		else if (s[i] == 'e' || s[i] == 'a' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
		{
			s[i] = 'e';
			cout << s << "x" << t << "\n";
		}
		else
		{
			cout << s << "ex" << t << "\n";
		}
	}
	return 0;
}
