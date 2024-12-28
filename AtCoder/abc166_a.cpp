#include <iostream>
using namespace std;

int main()
{
	char s[8];
	scanf("%s", s);
	s[1] = 'R' + 'B' - s[1];
	puts(s);
	return 0;
}
