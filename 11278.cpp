#include <stdio.h>

char tbl[127];

int main()
{
	int i;
	char ch;
	tbl['1'] = '1';
	tbl['2'] = '2';
	tbl['3'] = '3';
	tbl['4'] = 'q';
	tbl['5'] = 'j';
	tbl['6'] = 'l';
	tbl['7'] = 'm';
	tbl['8'] = 'f';
	tbl['9'] = 'p';
	tbl['0'] = '/';
	tbl['-'] = '[';
	tbl['='] = ']';
	tbl['q'] = '4';
	tbl['w'] = '5';
	tbl['e'] = '6';
	tbl['r'] = '.';
	tbl['t'] = 'o';
	tbl['y'] = 'r';
	tbl['u'] = 's';
	tbl['i'] = 'u';
	tbl['o'] = 'y';
	tbl['p'] = 'b';
	tbl['['] = ';';
	tbl[']'] = '=';
	tbl['\\'] = '\\';
	tbl['a'] = '7';
	tbl['s'] = '8';
	tbl['d'] = '9';
	tbl['f'] = 'a';
	tbl['g'] = 'e';
	tbl['h'] = 'h';
	tbl['j'] = 't';
	tbl['k'] = 'd';
	tbl['l'] = 'c';
	tbl[';'] = 'k';
	tbl['\''] = '-';
	tbl['z'] = '0';
	tbl['x'] = 'z';
	tbl['c'] = 'x';
	tbl['v'] = ',';
	tbl['b'] = 'i';
	tbl['n'] = 'n';
	tbl['m'] = 'w';
	tbl[','] = 'v';
	tbl['.'] = 'g';
	tbl['/'] = '\'';
	tbl['!'] = '!';
	tbl['@'] = '@';
	tbl['#'] = '#';
	tbl['$'] = 'Q';
	tbl['%'] = 'J';
	tbl['^'] = 'L';
	tbl['&'] = 'M';
	tbl['*'] = 'F';
	tbl['('] = 'P';
	tbl[')'] = '?';
	tbl['_'] = '{';
	tbl['+'] = '}';
	tbl['Q'] = '$';
	tbl['W'] = '%';
	tbl['E'] = '^';
	tbl['R'] = '>';
	tbl['T'] = 'O';
	tbl['Y'] = 'R';
	tbl['U'] = 'S';
	tbl['I'] = 'U';
	tbl['O'] = 'Y';
	tbl['P'] = 'B';
	tbl['{'] = ':';
	tbl['}'] = '+';
	tbl['|'] = '|';
	tbl['A'] = '&';
	tbl['S'] = '*';
	tbl['D'] = '(';
	tbl['F'] = 'A';
	tbl['G'] = 'E';
	tbl['H'] = 'H';
	tbl['J'] = 'T';
	tbl['K'] = 'D';
	tbl['L'] = 'C';
	tbl[':'] = 'K';
	tbl['"'] = '_';
	tbl['Z'] = ')';
	tbl['X'] = 'Z';
	tbl['C'] = 'X';
	tbl['V'] = '<';
	tbl['B'] = 'I';
	tbl['N'] = 'N';
	tbl['M'] = 'W';
	tbl['<'] = 'V';
	tbl['>'] = 'G';
	tbl['?'] = '"';
	for(i=0; i<127; i++)
	{
		if(!tbl[i])
		{
			tbl[i] = i;
		}
	}
	while(scanf("%c", &ch) == 1)
	{
		printf("%c", tbl[ch]);
	}
	return 0;
}
