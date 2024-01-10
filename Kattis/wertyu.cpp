#include <iostream>
using namespace std;

const char *key = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

char tbl[128];
char s[10005];

int main()
{
	int i;
	for (i=1; key[i]; i++)
	{
		tbl[key[i]] = key[i-1];
	}
	tbl[' '] = ' ';
	tbl['\n'] = '\n';
	while (fgets(s, sizeof(s), stdin))
	{
		for (i=0; s[i]; i++)
		{
			s[i] = tbl[s[i]];
		}
		fputs(s, stdout);
	}
	return 0;
}
