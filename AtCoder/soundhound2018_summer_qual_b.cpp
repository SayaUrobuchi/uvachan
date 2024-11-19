#include <iostream>
#include <cstring>
using namespace std;

const int N = 1005;

char s[N];

int main()
{
	int k, i;
	scanf("%s%d", s, &k);
	int n = strlen(s);
	for (i=0; i<n; i+=k)
	{
		putchar(s[i]);
	}
	puts("");
	return 0;
}
