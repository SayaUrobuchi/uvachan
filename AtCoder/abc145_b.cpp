#include <iostream>
#include <cstring>
using namespace std;

const int N = 128;

char s[N];

int main()
{
	int n;
	scanf("%d%s", &n, s);
	bool ans = !(n & 1) && strncmp(s, s+(n>>1), n>>1) == 0;
	puts(ans ? "Yes" : "No");
	return 0;
}
