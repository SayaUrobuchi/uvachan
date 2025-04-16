#include <iostream>
#include <cstring>
using namespace std;

const int SLEN = 128;

char s[SLEN], t[SLEN];

int main()
{
	scanf("%s%s", s, t);
	puts(strstr(s, t) ? "Yes" : "No");
	return 0;
}
