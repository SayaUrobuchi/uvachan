#include <iostream>
using namespace std;

int main()
{
	char s[8];
	scanf("%s", s);
	puts(s[2] == s[3] && s[4] == s[5] ? "Yes" : "No");
	return 0;
}
