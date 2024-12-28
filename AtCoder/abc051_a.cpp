#include <iostream>
using namespace std;

const int N = 32;

char s[N];

int main()
{
	scanf("%s", s);
	s[5] = ' ';
	s[13] = ' ';
	puts(s);
	return 0;
}
