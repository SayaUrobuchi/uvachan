#include <iostream>
using namespace std;

int main()
{
	string s;
	const char *ans[] = {"ist", "er"};
	cin >> s;
	puts(ans[s.back() == 'r']);
	return 0;
}
