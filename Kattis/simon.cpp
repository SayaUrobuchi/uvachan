#include <iostream>
using namespace std;

int main()
{
	int count;
	string s;
	cin >> count;
	getline(cin, s);
	while (count--)
	{
		getline(cin, s);
		if (s.size() > 11 && s.substr(0, 10) == "simon says")
		{
			cout << s.substr(11) << "\n";
		}
		else
		{
			cout << "\n";
		}
	}
	return 0;
}
