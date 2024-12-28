#include <iostream>
using namespace std;

int tbl[128];

int main()
{
	tbl['A'] = 'T';
	tbl['T'] = 'A';
	tbl['C'] = 'G';
	tbl['G'] = 'C';
	char c;
	scanf("%c", &c);
	putchar(tbl[c]);
	puts("");
	return 0;
}
