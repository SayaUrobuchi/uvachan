#include <iostream>
using namespace std;

const int N = 16;

char s[N];

int main()
{
	int i;
	scanf("%s", s);
	for (i=0; s[i]; i++)
	{
		putchar(s[i] ^ 1);
	}
	puts("");
	return 0;
}
