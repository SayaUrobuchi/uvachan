#include <iostream>
using namespace std;

const int N = 128;

char s[N];

int main()
{
	int n, i;
	scanf("%d%s", &n, s);
	for (i=0; i<n; i++)
	{
		putchar(s[i]);
		putchar(s[i]);
	}
	puts("");
	return 0;
}
