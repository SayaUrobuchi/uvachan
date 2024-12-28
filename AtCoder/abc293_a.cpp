#include <iostream>
using namespace std;

const int N = 128;

char buf[N];

int main()
{
	int i;
	scanf("%s", buf);
	string s = buf;
	for (i=1; i<s.size(); i+=2)
	{
		swap(s[i], s[i-1]);
	}
	puts(s.c_str());
	return 0;
}
