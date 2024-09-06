#include <iostream>
#include <cstring>
using namespace std;

const int N = 105;
const char *KEY = "keyence";

char s[N];

int main()
{
	int i, j;
	scanf("%s", s);
	int n = strlen(s);
	bool res = false;
	if (n >= 7)
	{
		for (i=0, j=7; i<=7&&!res; i++, j--)
		{
			if (strncmp(s, KEY, i) == 0 && strncmp(s+n-j, KEY+i, j) == 0)
			{
				res = true;
			}
		}
	}
	puts(res?"YES":"NO");
	return 0;
}
