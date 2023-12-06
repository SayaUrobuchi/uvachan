#include <iostream>
using namespace std;

char s[1024];

int main()
{
	int i;
	char last;
	fgets(s, sizeof(s), stdin);
	for (i=0, last=-1; s[i]; i++)
	{
		if (s[i] != last)
		{
			putchar(s[i]);
		}
		last = s[i];
	}
	return 0;
}
