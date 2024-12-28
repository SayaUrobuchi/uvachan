#include <iostream>
using namespace std;

const int N = 128;

char buf[N];

int main()
{
	scanf("%s", buf);
	string s = buf;
	printf("%c\n", s[s.size()/2]);
	return 0;
}
