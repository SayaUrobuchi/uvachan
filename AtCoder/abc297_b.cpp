#include <iostream>
using namespace std;

int main()
{
	int i;
	char s[32];
	scanf("%s", s);
	string pat;
	string bb;
	for (i=0; s[i]; i++)
	{
		if (s[i] == 'B')
		{
			bb += '0' + i;
		}
		else if (s[i] == 'R' || s[i] == 'K')
		{
			pat += s[i];
		}
	}
	if ((bb[0] & 1) != (bb[1] & 1) && pat == "RKR")
	{
		puts("Yes");
	}
	else
	{
		puts("No");
	}
	return 0;
}
