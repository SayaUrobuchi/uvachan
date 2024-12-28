#include <iostream>
using namespace std;

const int N = 128;

int tbl[128];
char s[N];

int main()
{
	int n, i;
	tbl['J'] = 'O';
	tbl['O'] = 'I';
	tbl['I'] = 'J';
	scanf("%d%s", &n, s);
	for (i=0; i<n; i++)
	{
		s[i] = tbl[ s[i] ];
	}
	puts(s);
	return 0;
}