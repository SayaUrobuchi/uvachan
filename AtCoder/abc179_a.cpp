#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;
	if (s.back() == 's')
	{
		s += "es";
	}
	else
	{
		s += "s";
	}
	puts(s.c_str());
	return 0;
}
