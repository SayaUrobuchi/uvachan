#include <iostream>
using namespace std;

char s[128];

int main()
{
	int t;
	scanf("%[^\r\n]", s+1);
	while (scanf("%3d", &t) == 1)
	{
		putchar(s[t]);
	}
	puts("");
	return 0;
}