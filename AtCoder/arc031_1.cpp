#include <iostream>
using namespace std;

const int N = 128;

char buf[N];

int main()
{
	int i;
	scanf("%s", buf);
	string s = buf;
	bool is_palin = true;
	for (i=0; i<s.size()&&is_palin; i++)
	{
		if (s[i] != s.back())
		{
			is_palin = false;
		}
		s.pop_back();
	}
	puts(is_palin ? "YES" : "NO");
	return 0;
}
