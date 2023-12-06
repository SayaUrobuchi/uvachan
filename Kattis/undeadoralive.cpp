#include <iostream>
using namespace std;

const char *nam[] = {"machine", "undead", "alive", "double agent"};

char s[256];

int main()
{
	int i, typ;
	fgets(s, sizeof(s), stdin);
	for (i=0, typ=0; s[i]&&s[i+1]; i++)
	{
		if (s[i] == ':')
		{
			if (s[i+1] == '(')
			{
				typ |= 1;
			}
			else if (s[i+1] == ')')
			{
				typ |= 2;
			}
		}
	}
	puts(nam[typ]);
	return 0;
}
