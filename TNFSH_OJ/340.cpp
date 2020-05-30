#include <iostream>
using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		s[0] &= ~32;
		cout << " Nice to see you, " << s << "!\n";
	}
	return 0;
}
