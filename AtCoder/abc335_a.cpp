#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;
	s.back() = '4';
	puts(s.c_str());
	return 0;
}
