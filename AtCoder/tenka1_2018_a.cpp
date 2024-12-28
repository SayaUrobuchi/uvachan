#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	char s[8];
	scanf("%s", s);
	if (s[2])
	{
		reverse(s, s+3);
	}
	puts(s);
	return 0;
}