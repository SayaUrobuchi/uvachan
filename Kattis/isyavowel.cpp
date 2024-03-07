#include <iostream>
using namespace std;

int tbl[128];
char s[64];

int main()
{
	int i;
	tbl['a'] = tbl['e'] = tbl['i'] = tbl['o'] = tbl['u'] = 1;
	fgets(s, sizeof(s), stdin);
	int a = 0;
	int y = 0;
	for (i=0; isalpha(s[i]); i++)
	{
		a += tbl[s[i]];
		y += (s[i] == 'y');
	}
	printf("%d %d\n", a, a+y);
	return 0;
}
