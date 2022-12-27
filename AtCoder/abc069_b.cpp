#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;
	printf("%c%d%c\n", s[0], (int)s.size()-2, s.back());
	return 0;
}