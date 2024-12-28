#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;
	string ans;
	while (ans.size() < 6)
	{
		ans += s;
	}
	puts(ans.c_str());
	return 0;
}
