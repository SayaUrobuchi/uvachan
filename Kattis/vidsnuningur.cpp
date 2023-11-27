#include <iostream>
#include <algorithm>
using namespace std;

char s[1005];

int main()
{
	int n;
	scanf("%s", s);
	for (n=0; s[n]; ++n);
	reverse(s, s+n);
	puts(s);
	return 0;
}
