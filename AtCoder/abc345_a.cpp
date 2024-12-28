#include <iostream>
using namespace std;

const int N = 128;

char buf[N];

int main()
{
	scanf("%s", buf);
	string s = buf;
	string t = '<' + string(s.size()-2, '=') + '>';
	puts(s == t ? "Yes" : "No");
	return 0;
}
