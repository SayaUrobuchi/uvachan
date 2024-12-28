#include <iostream>
using namespace std;

const int N = 16;

char s[N];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	--m;
	scanf("%s", s);
	s[m] = tolower(s[m]);
	puts(s);
	return 0;
}
