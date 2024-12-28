#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;
	string ans = '0' + s;
	ans.pop_back();
	puts(ans.c_str());
	return 0;
}
