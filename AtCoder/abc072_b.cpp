#include <iostream>
using namespace std;

char s[200005];

int main()
{
	int i;
	scanf("%s", s);
	for (i=0; s[i]; i++)
	{
		if (!(i & 1))
		{
			putchar(s[i]);
		}
	}
	puts("");
	return 0;
}