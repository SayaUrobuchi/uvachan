#include <iostream>
using namespace std;

const int N = 128;

char buf[2][N];

int main()
{
	scanf("%s%s", buf[0], buf[1]);
	string s = buf[0];
	string t = buf[1];
	bool is_prefix = (s.size() <= t.size());
	if (is_prefix)
	{
		if (s != t.substr(0, s.size()))
		{
			is_prefix = false;
		}
	}
	puts(is_prefix ? "Yes" : "No");
	return 0;
}
