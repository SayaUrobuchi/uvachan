#include <iostream>
using namespace std;

const int N = 128;

char buf[N];

int main()
{
	scanf("%s", buf);
	string s = buf;
	bool ans = (s.size() >= 3 && s.substr(s.size()-3) == "san");
	puts(ans ? "Yes" : "No");
	return 0;
}
