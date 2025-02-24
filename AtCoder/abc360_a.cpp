#include <iostream>
using namespace std;

int main()
{
	int i;
	char s[32];
	scanf("%s", s);
	bool ok;
	for (i=0; s[i]; i++)
	{
		if (s[i] != 'S')
		{
			ok = (s[i] == 'R');
			break;
		}
	}
	puts(ok ? "Yes" : "No");
	return 0;
}
