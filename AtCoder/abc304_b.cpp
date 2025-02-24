#include <iostream>
using namespace std;

int main()
{
	char buf[32];
	scanf("%s", buf);
	string s = buf;
	string zero(16, '0');
	printf("%.3s%.*s\n", s.c_str(), max(0, (int)s.size()-3), zero.c_str());
	return 0;
}
