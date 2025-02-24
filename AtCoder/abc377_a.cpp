#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	char buf[4];
	scanf("%s", buf);
	string s = buf;
	sort(s.begin(), s.end());
	puts(s == "ABC" ? "Yes" : "No");
	return 0;
}
