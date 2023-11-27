#include <iostream>
using namespace std;

const char *PAT = "%[^|]|%[^|\r\n]%*[\r\n]";
const int N = 2200;

char s[2][N], t[2][N];

int main()
{
	scanf(PAT, s[0], t[0]);
	scanf(PAT, s[1], t[1]);
	printf("%s%s %s%s\n", s[0], s[1], t[0], t[1]);
	return 0;
}
