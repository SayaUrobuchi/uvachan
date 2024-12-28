#include <iostream>
using namespace std;

const int N = 128;

char s[N], t[N];

int main()
{
	int n, i;
	scanf("%d", &n);
	scanf("%s%s", s, t);
	for (i=0; i<n; i++)
	{
		putchar(s[i]);
		putchar(t[i]);
	}
	puts("");
	return 0;
}
